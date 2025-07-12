/**
 * @author: Mitul Tyagi
 * @description: Task Queue Round-Robin Scheduler
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep (simulation only)
#include <stdbool.h>

#define TASKSCOUNT 3

typedef void (*taskptr)();

typedef struct task_t
{
    bool isActive;
    taskptr taskhandler;
} task;

task queue[TASKSCOUNT];

void task1()
{
    printf("Task 1 executed\n");
}

void task2()
{
    printf("Task 2 executed\n");
}

void task3()
{
    printf("Task 3 executed\n");
}

void register_task(taskptr handler, int index)
{
    if (index < 0 || index >= TASKSCOUNT)
    {
        printf("Invalid task index: %d\n", index);
        return;
    }
    queue[index].isActive = 1;
    queue[index].taskhandler = handler;
}

void unregister_task(int index)
{
    if (index < 0 || index >= TASKSCOUNT)
        return;

    queue[index].isActive = 0;
    queue[index].taskhandler = NULL;
}

void scheduler()
{
    int i = 0;
    int count = 0;
    while (1)
    {
        if (queue[i].isActive && queue[i].taskhandler)
            queue[i].taskhandler();

        i = (i + 1) % TASKSCOUNT;
        sleep(1);

        if (++count > 10)
            break; // Simulate for 10 task runs
    }
}

int main()
{
    register_task(task1, 0);
    register_task(task2, 1);
    register_task(task3, 2);
    scheduler();
    return 0;
}