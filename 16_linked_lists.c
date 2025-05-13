/**
 * @author: Mitul Tyagi
 * @description: Linked Lists
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
int totalElements = 0;
int reverseCount = 0;
int forwardCount = 0;

Node *create_node(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    totalElements++;
    return temp;
}

void traverse_linked_list_forward(void)
{
    Node *temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        pos++;
        printf(" (%d,%d) -->", temp->data, pos);
        temp = temp->next;
    }
    printf(" Null\n");
    return;
}

void traverse_linked_list_forward_recursion(Node *node)
{
    forwardCount++;
    if (node == NULL)
        return;
    printf(" (%d,%d) -->", node->data, forwardCount);
    if (node->next == NULL)
    {
        printf(" Null\n");
        return;
    }
    traverse_linked_list_forward_recursion(node->next);
    return;
}

void traverse_linked_list_backward(Node *node)
{
    reverseCount++;
    if (node->next == NULL)
    {
        printf("Printing the list in the reverse order\n");
        printf(" NULL <-- (%d,%d)", node->data, reverseCount);
        return;
    }
    traverse_linked_list_backward(node->next);
    reverseCount--;
    printf(" <-- (%d,%d)", node->data, reverseCount);
    return;
}

void insert_node_at_beginning(int data)
{
    printf("----------------------------------\n");
    printf("Inserting %d at beginning\n", data);
    Node *node = create_node(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head = node;
    return;
}

void insert_node_at_end(int data)
{
    printf("----------------------------------\n");
    printf("Inserting %d at end\n", data);
    Node *node = create_node(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    return;
}

void insert_node_at_position(int data, int pos)
{
    printf("----------------------------------\n");
    printf("Inserting %d at index %d\n", data, pos);
    if (pos > totalElements + 2)
    {
        printf("Error!!!.....\nPosition more than the number of elements.\n");
        return;
    }
    if (pos == 1)
    {
        insert_node_at_beginning(data);
        return;
    }
    if (pos == totalElements + 1)
    {
        insert_node_at_end(data);
        return;
    }
    int index = 0;
    Node *temp = head;
    Node *new = create_node(data);
    for (index = 0; index < pos - 2; index++)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    return;
}

void delete_node_at_beginning(void)
{
    printf("----------------------------------\n");
    printf("Deleting at beginning\n");
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    free(temp);
    totalElements--;
    return;
}

void delete_node_at_end(void)
{
    printf("----------------------------------\n");
    printf("Deleting at beginning\n");
    if (head == NULL)
        return;
    Node *temp = head;
    Node *prev = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == temp)
        head = NULL;
    else
        prev->next = NULL;
    free(temp);
    totalElements--;
    return;
}

void delete_at_position(int pos)
{
    printf("----------------------------------\n");
    printf("Deleting at position: %d\n", pos);
    if (pos > totalElements)
    {
        printf("Error!!!.....\nPosition more than the number of elements.\n");
        return;
    }
    if (pos == 1)
    {
        delete_node_at_beginning();
        return;
    }
    if (pos == totalElements)
    {
        delete_node_at_end();
        return;
    }
    int index = 0;
    Node *temp = head;
    Node *prev = head;
    for (index = 0; index < pos - 1; index++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    totalElements--;
    return;
}

void reverse_linked_list(void)
{
    if (head->next == NULL || head == NULL)
        return;
    Node *current;
    Node *prev;
    Node *next;
    current = head;
    next = NULL;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    forwardCount = 0;
    traverse_linked_list_forward_recursion(head);
    return;
}

void reverse_linked_list_recursion(Node *node)
{
    if (node == NULL)
        return;
    if (node->next == NULL)
    {
        head = node;
        return;
    }
    reverse_linked_list_recursion(node->next);
    Node *temp = node->next;
    temp->next = node;
    node->next = NULL;
    return;
}

void getmiddleNode(Node *head)
{
    Node *slow_p = head, *fast_p = head;

    int index = 1;

    while (fast_p && fast_p->next)
    {
        index++;
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
    }
    printf("Middle Node: %d at index %d\n", slow_p->data, index);
    return;
}
int main(int argc, char const *argv[])
{
    insert_node_at_beginning(5);
    traverse_linked_list_forward();
    delete_node_at_beginning();
    traverse_linked_list_forward();
    insert_node_at_beginning(8);
    traverse_linked_list_forward();
    insert_node_at_beginning(10);
    traverse_linked_list_forward();
    insert_node_at_beginning(522);
    traverse_linked_list_forward();
    insert_node_at_beginning(11);
    traverse_linked_list_forward();
    insert_node_at_beginning(78);
    traverse_linked_list_forward();
    insert_node_at_end(12);
    traverse_linked_list_forward();
    insert_node_at_end(40);
    traverse_linked_list_forward();
    insert_node_at_end(88);
    traverse_linked_list_forward();
    insert_node_at_end(1);
    traverse_linked_list_forward();
    insert_node_at_position(1551, 6);
    traverse_linked_list_forward();
    insert_node_at_position(999, 10);
    traverse_linked_list_forward();
    insert_node_at_position(3443, 1);
    traverse_linked_list_forward();
    insert_node_at_position(6776, 13);
    traverse_linked_list_forward();
    insert_node_at_position(4434, 18);
    traverse_linked_list_forward();
    delete_node_at_end();
    traverse_linked_list_forward();
    delete_at_position(6);
    traverse_linked_list_forward();
    delete_at_position(1);
    traverse_linked_list_forward();
    delete_at_position(10);
    traverse_linked_list_forward();
    reverseCount = 0;
    traverse_linked_list_backward(head);
    printf("\n");
    traverse_linked_list_forward_recursion(head);
    printf("Reversing the Linked List\n");
    reverse_linked_list();
    reverse_linked_list_recursion(head);
    traverse_linked_list_forward();
    getmiddleNode(head);
    return 0;
}
/*
Inserting 5 at beginning
Deleting at beginning
Null
Inserting 8 at beginning
(8,1) --> Null
Inserting 10 at beginning
(10,1) --> (8,2) --> Null
Inserting 522 at beginning
(522,1) --> (10,2) --> (8,3) --> Null
Inserting 11 at beginning
(11,1) --> (522,2) --> (10,3) --> (8,4) --> Null
Inserting 78 at beginning
(78,1) --> (11,2) --> (522,3) --> (10,4) --> (8,5) --> Null
Inserting 12 at end
(78,1) --> (11,2) --> (522,3) --> (10,4) --> (8,5) --> (12,6) --> NullInserting
40 at end (78,1) --> (11,2) --> (522,3) --> (10,4) --> (8,5) --> (12,6) -->
(40,7) --> Null Inserting 88 at end (78,1) --> (11,2) --> (522,3) --> (10,4) -->
(8,5) --> (12,6) --> (40,7) --> (88,8) --> Null Inserting 1 at end (78,1) -->
(11,2) --> (522,3) --> (10,4) --> (8,5) --> (12,6) --> (40,7) --> (88,8) -->
(1,9) --> Null Inserting 1551 at position: 6 (78,1) --> (11,2) --> (522,3) -->
(10,4) --> (8,5) --> (1551,6) --> (12,7) --> (40,8) --> (88,9) --> (1,10) -->
Null Inserting 999 at position: 10 (78,1) --> (11,2) --> (522,3) --> (10,4) -->
(8,5) --> (1551,6) --> (12,7) --> (40,8) --> (88,9) --> (999,10) --> (1,11) -->
Null Inserting 3443 at position: 1 Inserting 3443 at beginning (3443,1) -->
(78,2) --> (11,3) --> (522,4) --> (10,5) --> (8,6) --> (1551,7) --> (12,8) -->
(40,9) --> (88,10) --> (999,11) --> (1,12) --> Null Inserting 6776 at position:
13 Inserting 6776 at end (3443,1) --> (78,2) --> (11,3) --> (522,4) --> (10,5)
--> (8,6) --> (1551,7) --> (12,8) --> (40,9) --> (88,10) --> (999,11) --> (1,12)
--> (6776,13) --> Null Inserting 4434 at position: 18 Error!!!..... Position
more than the number of elements. (3443,1) --> (78,2) --> (11,3) --> (522,4) -->
(10,5) --> (8,6) --> (1551,7) --> (12,8) --> (40,9) --> (88,10) --> (999,11) -->
(1,12) --> (6776,13) --> Null
Deleting at end
(3443,1) --> (78,2) --> (11,3) --> (522,4) --> (10,5) --> (8,6) --> (1551,7) -->
(12,8) --> (40,9) --> (88,10) --> (999,11) --> (1,12) --> Null Deleting at
position: 6 (3443,1) --> (78,2) --> (11,3) --> (522,4) --> (10,5) --> (1551,6)
--> (12,7) --> (40,8) --> (88,9) --> (999,10) --> (1,11) --> Null Deleting at
position: 1 Deleting at beginning (78,1) --> (11,2) --> (522,3) --> (10,4) -->
(1551,5) --> (12,6) --> (40,7) --> (88,8) --> (999,9) --> (1,10) --> Null
Deleting at position: 10
Deleting at end
(78,1) --> (11,2) --> (522,3) --> (10,4) --> (1551,5) --> (12,6) --> (40,7) -->
(88,8) --> (999,9) --> Null Printing the list in the reverse order NULL <--
(999,9) <-- (88,8) <-- (40,7) <-- (12,6) <-- (1551,5) <-- (10,4) <-- (522,3) <--
(11,2) <-- (78,1) (78,1) --> (11,2) --> (522,3) --> (10,4) --> (1551,5) -->
(12,6) --> (40,7) --> (88,8) --> (999,9) --> Null Reversing the Linked List
(999,1) --> (88,2) --> (40,3) --> (12,4) --> (1551,5) --> (10,6) --> (522,7) -->
(11,8) --> (78,9) --> Null (78,1)
*/
