/**
 * @author: Mitul Tyagi
 * @description: Hash Table Demo
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 15
#define PRIME_NUM 13
typedef struct Node_t
{
    int index;
    char *name;
    struct Node_t *next;
} Node;

int hash_function(int value)
{
    int hash_value = abs((value % PRIME_NUM));
    return hash_value;
}

void hash_table_init(Node *ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ht[i].next = NULL;
        ht[i].index = -1;
        ht[i].name = "";
    }
}

void fill_hash_table(int val, char *name, Node *ht)
{
    int hash = hash_function(val);
    if (ht[hash].index == -1)
    {
        ht[hash].index = val;
        ht[hash].name = name;
        return;
    }
    Node *temp = (Node *)&ht[hash];
    while (temp->next != NULL)
        temp = temp->next;
    Node *new = (Node *)malloc(sizeof(Node));
    new->index = val;
    new->next = NULL;
    new->name = name;
    temp->next = new;
    return;
}

Node *get_value(int val, Node *ht)
{
    int hash = hash_function(val);
    if (ht[hash].index == -1)
        return NULL;
    if (ht[hash].index == val)
    {
        return &ht[hash];
    }
    Node *temp = (ht[hash].next);
    while (temp != NULL)
    {
        if (temp->index == val)
            return temp;
        temp = temp->next;
    }
}
void display_hash_table(Node *ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (ht[i].index == -1)
        {
            printf("%d: -1\n", i);
            continue;
        }
        printf("%d : ", i);
        Node *temp = &ht[i];
        while (temp != NULL)
        {
            printf("(%d,%s)-> ", temp->index, temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}
int main(int argc, char const *argv[])
{
    // Both the below declarations work.
    // Node hash_table[TABLE_SIZE]; // static allocation on stack
    Node *hash_table = (Node *)malloc(sizeof(Node) * TABLE_SIZE); // dynamic allocation on heap
    hash_table_init(hash_table);
    fill_hash_table(34, "John", hash_table);
    fill_hash_table(367, "Liam", hash_table);
    fill_hash_table(12, "Wells", hash_table);
    fill_hash_table(89, "Marry", hash_table);
    fill_hash_table(6, "Lie", hash_table);
    fill_hash_table(4, "Smith", hash_table);
    fill_hash_table(100, "Mohan", hash_table);
    fill_hash_table(25, "Root", hash_table);

    display_hash_table(hash_table);
    printf("%s\n", get_value(89, hash_table)->name);

    return 0;
}
