/**
 * @author: Mitul Tyagi
 * @description: Doubly Linked Lists
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

} Node;

Node *head = NULL;
int totalElements = 0;
int forwardCount = 0;
int reverseCount = 0;

Node *create_node(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    totalElements++;
    return temp;
}

void traverse_linked_list_forward(void)
{
    Node *temp = head;
    int pos = 0;
    printf("---------------Traversal-------------------\n");
    // printf("Total Elements: %d\n", totalElements);
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
    if (node == NULL)
    {
        printf(" Null\n");
        return;
    }
    forwardCount++;
    printf(" (%d,%d) -->", node->data, forwardCount);
    traverse_linked_list_forward_recursion(node->next);
    return;
}

void traverse_linked_list_backward(Node *node)
{
    if (node == NULL)
    {
        printf(" Null\n");
        return;
    }
    reverseCount++;
    if (node->next == NULL)
    {
        printf("---------------Reverse Traversal-------------------\n");
        printf(" NULL <-- (%d,%d)", node->data, reverseCount);
        return;
    }
    traverse_linked_list_backward(node->next);
    reverseCount--;
    printf(" <-- (%d,%d)", node->data, reverseCount);
    return;
}

int insert_node_at_beginning(int data)
{
    printf("----------------------------------\n");
    printf("Inserting %d at beginning\n", data);
    Node *temp = create_node(data);
    if (head == NULL)
    {
        head = temp;
        return 1;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    return 1;
}

int insert_node_at_end(int data)
{
    printf("----------------------------------\n");
    printf("Inserting %d at end\n", data);
    Node *temp = create_node(data);
    if (head == NULL)
    {
        head = temp;
        return 1;
    }
    Node *traverse_node = head;
    while (traverse_node->next != NULL)
        traverse_node = traverse_node->next;
    traverse_node->next = temp;
    temp->prev = traverse_node;
    return 1;
}

int insert_node_at_position(int data, int pos)
{
    printf("----------------------------------\n");
    printf("Inserting %d at index %d\n", data, pos);
    if (pos > totalElements)
        return -1;
    if (pos == 1)
    {
        insert_node_at_beginning(data);
        return 1;
    }
    if (pos == totalElements)
    {
        insert_node_at_end(data);
        return 1;
    }
    int index = 0;
    Node *temp = create_node(data);
    if (head == NULL)
    {
        head = temp;
        return 1;
    }
    Node *traverse_node = head;
    while (traverse_node->next != NULL)
    {
        index++;
        if (index == pos)
            break;
        traverse_node = traverse_node->next;
    }
    temp->prev = traverse_node->prev;
    temp->next = traverse_node;
    traverse_node->prev->next = temp;
    traverse_node->prev = temp;
    return 1;
}

void delete_node_at_beginning(void)
{
    printf("----------------------------------\n");
    printf("Deleting at beginning\n");
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        totalElements--;
        head = NULL;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
    totalElements--;
    return;
}

void delete_node_at_end(void)
{
    printf("----------------------------------\n");
    printf("Deleting at end\n");
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        totalElements--;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    temp->prev = NULL;
    free(temp);
    totalElements--;
    return;
}

int delete_at_position(int pos)
{
    printf("----------------------------------\n");
    printf("Deleting at position %d\n", pos);
    if (pos > totalElements)
        return -1;
    if (pos == 1)
    {
        delete_node_at_beginning();
        return 1;
    }
    if (pos == totalElements)
    {
        delete_node_at_end();
        return 1;
    }
    int index = 0;
    Node *traverse_node = head;
    while (traverse_node->next != NULL)
    {
        index++;
        if (index == pos)
            break;
        traverse_node = traverse_node->next;
    }
    traverse_node->prev->next = traverse_node->next;
    traverse_node->next->prev = traverse_node->prev;
    traverse_node->next = NULL;
    traverse_node->prev = NULL;
    free(traverse_node);
    totalElements--;
    return 1;
}

void reverse_doubly_linked_list(void)
{
    if ((head == NULL) || (head->next == NULL))
        return;
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        prev = current->prev;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    head = prev;
    return;
}

void reverse_doubly_linked_list_recursion(Node *node)
{
    if (node == NULL)
        return;
    Node *next = NULL;
    if (node->next == NULL)
    {
        head = node;
        next = node->next;
        node->next = node->prev;
        node->prev = next;
        return;
    }
    reverse_doubly_linked_list_recursion(node->next);
    next = node->next;
    node->next = node->prev;
    node->prev = next;
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
    printf("---------------Traversal(Using Recursion)-------------------\n");
    traverse_linked_list_forward_recursion(head);
    printf("Reversing the Linked List\n");
    reverse_doubly_linked_list();
    traverse_linked_list_forward();
    reverse_doubly_linked_list_recursion(head);
    traverse_linked_list_forward();
    getmiddleNode(head);
    return 0;
}
