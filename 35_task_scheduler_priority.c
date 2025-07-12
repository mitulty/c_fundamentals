/**
 * @author: Mitul Tyagi
 * @description: Task Queue Priority Scheduler
 */
/**
- Ways to Allow Lower-Priority Tasks to Run
 * 1. Use a priority queue where tasks with lower priority numbers are executed first.
 * 2. Implement a time slice mechanism where each task gets a chance to run based on its priority.
 * 3. Allow lower-priority tasks to run when higher-priority tasks are not ready or waiting.
- Cooperative Yielding
    The higher-priority task can choose to voluntarily yield or deactivate itself:
    void task2() {
    printf("Task 2 executed\n");

    // Simulate that it only runs for some time, then disables itself
    static int count = 0;
    if (++count >= 3) {
        unregister_task(1); // Voluntarily yield after 3 runs
    }
}
-  Aging (Priority Boost Over Time): You can implement priority aging to gradually boost lower-priority
tasks if they’re waiting too long. Add a waitCount field to each task. If a task waits too many cycles,
temporarily increase its priority. This helps avoid starvation and gives all tasks a chance to run.
- Hybrid: Priority + Round-Robin Within Same Priority. If multiple tasks have the same priority, use
round-robin among them. If only the highest-priority task(s) exist, round-robin among those.
- Time-Sliced Fair Scheduling: Instead of always picking the highest priority, assign a fixed time slice
quota or count-based quota to each task.Let each task run for N ticks even if a higher-priority one is available.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define TASKSCOUNT 3
#define MAX_PRIORITY 255 // Larger number means lower priority

typedef void (*taskptr)();

typedef struct task_t
{
    bool isActive;
    uint8_t priority;
    taskptr taskhandler;
    int waitCount; // For aging or yielding
    // Add more fields if needed, like task ID, execution count, etc.
} task;

task queue[TASKSCOUNT];

void task0() { printf("Task 0 executed\n"); }
void task1() { printf("Task 1 executed\n"); }
void task2() { printf("Task 2 executed\n"); }

void register_task(taskptr handler, int index, uint8_t priority)
{
    if (index < 0 || index >= TASKSCOUNT)
    {
        printf("Invalid task index: %d\n", index);
        return;
    }
    queue[index].isActive = true;
    queue[index].priority = priority;
    queue[index].taskhandler = handler;
    queue[index].waitCount = 0; // Initialize wait count
}

void unregister_task(int index)
{
    if (index < 0 || index >= TASKSCOUNT)
        return;

    queue[index].isActive = false;
    queue[index].taskhandler = NULL;
}

void scheduler()
{
    int selectedTask = -1;
    uint8_t minPriority = MAX_PRIORITY;

    while (1)
    {
        for (int i = 0; i < TASKSCOUNT; ++i)
        {
            if (queue[i].isActive && queue[i].taskhandler != NULL)
            {
                if (queue[i].priority < minPriority && queue[i].waitCount < 3) // Only consider tasks that are not waiting too long
                {
                    // Select the task with the lowest priority number (higher priority)
                    selectedTask = i;
                    minPriority = queue[i].priority;
                }
                else if (queue[i].waitCount >= 3) // If waiting too long, consider it for execution
                {
                    minPriority = 0;
                    selectedTask = i;
                }
            }
        }
        printf("------------------------------\n");
        printf("Selected Task: %d with Priority: %d and wait count: %d\n",
               selectedTask, queue[selectedTask].priority, queue[selectedTask].waitCount);
        if (selectedTask != -1)
        {
            queue[selectedTask].taskhandler();
            queue[selectedTask].waitCount = 0; // Reset wait count after boosting
        }
        else
        {
            printf("No active tasks available.\n");
        }
        for (int i = 0; i < TASKSCOUNT; ++i)
        {
            if (queue[i].isActive && queue[i].taskhandler != NULL && i != selectedTask)
            {
                // Increment wait count for aging
                queue[i].waitCount++;
            }
        }
        selectedTask = -1;          // Reset for next iteration
        minPriority = MAX_PRIORITY; // Reset minimum priority
        printf("Waiting for next cycle...\n");
        sleep(1); // Simulate time delay
    }
}

int main()
{
    // Lower number = higher priority
    register_task(task0, 0, 2); // Medium priority
    register_task(task1, 1, 1); // High priority
    register_task(task2, 2, 3); // Low priority

    scheduler();
    return 0;
}

/**
------------------------------
Selected Task: 1 with Priority: 1 and wait count: 0
Task 1 executed  ----------------------------------------------> (1,0,1)
Waiting for next cycle...
------------------------------
Selected Task: 1 with Priority: 1 and wait count: 0
Task 1 executed ----------------------------------------------> (2,0,2)
Waiting for next cycle...
------------------------------
Selected Task: 1 with Priority: 1 and wait count: 0
Task 1 executed ----------------------------------------------> (3,0,3)
Waiting for next cycle...
------------------------------
Selected Task: 2 with Priority: 3 and wait count: 3
Task 2 executed ----------------------------------------------> (4,1,0)
Waiting for next cycle...
------------------------------
Selected Task: 0 with Priority: 2 and wait count: 4
Task 0 executed ----------------------------------------------> (0,2,1)
Waiting for next cycle...
------------------------------
Selected Task: 1 with Priority: 1 and wait count: 2
Task 1 executed ----------------------------------------------> (1,0,2)
Waiting for next cycle...
------------------------------
Selected Task: 1 with Priority: 1 and wait count: 0
Task 1 executed ----------------------------------------------> (2,0,3)
Waiting for next cycle...
------------------------------
Selected Task: 2 with Priority: 3 and wait count: 3
Task 2 executed ----------------------------------------------> (3,1,0)
Waiting for next cycle...
------------------------------
Selected Task: 0 with Priority: 2 and wait count: 3
Task 0 executed ----------------------------------------------> (0,2,1)
Waiting for next cycle...
------------------------------
Selected Task: 1 with Priority: 1 and wait count: 2
Task 1 executed ----------------------------------------------> (1,0,2)
Waiting for next cycle...
 */