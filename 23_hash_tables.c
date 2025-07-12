/**
 * @author: Mitul Tyagi
 * @description: Hash Table
 */
/*
- A hash table in C/C++ is a data structure that maps keys to values. A hash
table uses a hash function to compute indexes for a key. The benefit of using a
hash table is its very fast access time. Typically, the time complexity
(amortized time complexity) is a constant O(1) access time.
- A hash table is a container data structure that allows to quickly look up a
key (often a string) to find its corresponding value (any data type). Under the
hood, they’re arrays that are indexed by a hash function of the key. A hash
function turns a key into a random-looking number, and it must always return the
same number given the same key. It implements an abstract array data type.
- When the hash function generates the same index for multiple keys, there will
be a conflict (what value to be stored in that index). This is called a hash
collision. This can be resolved using Chaining or Open Addressing. A good hash
function may not prevent the collisions completely however it can reduce the
number of collisions.
- In chaining, if a hash function produces the same index for multiple elements,
these elements are stored in the same index by using a doubly-linked list. The
value returned by the Hash function is the bucket index for a key in a separate
chaining method. Each index in the array is called a bucket as it is a bucket of
a linked list.
- Unlike chaining, open addressing doesn't store multiple elements into the same
slot. Here, each slot is either filled with a single key or left NIL. Linear
probing is a common technique. In linear probing, collision is resolved by
checking the next slot. If a collision occurs at h(k, 0), then h(k, 1) is
checked. In this way, the value of i is incremented linearly. The problem with
linear probing is that a cluster of adjacent slots is filled. When inserting a
new element, the entire cluster must be traversed. This adds to the time
required to perform operations on the hash table. In case of a quadratic probing
the space between the slots is increased. In double hashing if a collision
occurs after applying a hash function h(k), then another hash function is
calculated for finding the next slot that is h(k, i) = (h1(k) + ih2(k)) mod m.
- Hash tables are implemented where constant time lookup and insertion is
required, cryptographic applications and indexing data is required.
- Rehashing is a concept that reduces collision when the elements are increased
in the current hash table. It will make a new array of doubled size and copy the
previous array elements to it.
- The time complexity of hash table insertion and deletion operations is O(1) on
average. Time Complexity of Insertion - in the average case it is constant. In
the worst case, it is linear. Time Complexity of Search - in the average case it
is constant. In the worst case, it is linear. Time Complexity of Deletion - In
average cases it is constant. In the worst case, it is linear. Space Complexity
- O(n) as it has n number of elements.

*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20000

typedef struct entry
{
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct hash_table
{
    entry_t **entries;
} ht_t;

unsigned int hash(const char *key)
{
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // do several rounds of multiplication
    for (; i < key_len; ++i)
    {
        value = value * 37 + key[i];
    }

    // make sure value is 0 <= value < TABLE_SIZE
    value = value % TABLE_SIZE;

    return value;
}

entry_t *ht_pair(const char *key, const char *value)
{
    // allocate the entry
    entry_t *entry = malloc(sizeof(entry_t) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    // copy the key and value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

ht_t *ht_create(void)
{
    // allocate table
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    // allocate table entries
    hashtable->entries = (entry_t **)malloc(sizeof(entry_t *) * TABLE_SIZE);

    // set each to null (needed for proper operation)
    int i = 0;
    for (; i < TABLE_SIZE; ++i)
    {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

void ht_set(ht_t *hashtable, const char *key, const char *value)
{
    unsigned int slot = hash(key);

    // try to look up an entry set
    entry_t *entry = hashtable->entries[slot];

    // NULL entry means slot empty, insert immediately
    if (entry == NULL)
    {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    entry_t *prev;

    // walk through each entry until either the end is
    // reached or a matching key is found
    while (entry != NULL)
    {
        // check key
        if (strcmp(entry->key, key) == 0)
        {
            // match found, replace value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;
    }

    // end of chain reached without a match, add new
    prev->next = ht_pair(key, value);
}

char *ht_get(ht_t *hashtable, const char *key)
{
    unsigned int slot = hash(key);

    // try to find a valid slot
    entry_t *entry = hashtable->entries[slot];

    // no slot means no entry
    if (entry == NULL)
    {
        return NULL;
    }

    // walk through each entry in the slot, which could just be a single thing
    while (entry != NULL)
    {
        // return value if found
        if (strcmp(entry->key, key) == 0)
        {
            return entry->value;
        }

        // proceed to next key if available
        entry = entry->next;
    }

    // reaching here means there were >= 1 entries but no key match
    return NULL;
}

void ht_del(ht_t *hashtable, const char *key)
{
    unsigned int bucket = hash(key);

    // try to find a valid bucket
    entry_t *entry = hashtable->entries[bucket];

    // no bucket means no entry
    if (entry == NULL)
    {
        return;
    }

    entry_t *prev;
    int idx = 0;

    // walk through each entry until either the end is reached or a matching key
    // is found
    while (entry != NULL)
    {
        // check key
        if (strcmp(entry->key, key) == 0)
        {
            // first item and no next entry
            if (entry->next == NULL && idx == 0)
            {
                hashtable->entries[bucket] = NULL;
            }

            // first item with a next entry
            if (entry->next != NULL && idx == 0)
            {
                hashtable->entries[bucket] = entry->next;
            }

            // last item
            if (entry->next == NULL && idx != 0)
            {
                prev->next = NULL;
            }

            // middle item
            if (entry->next != NULL && idx != 0)
            {
                prev->next = entry->next;
            }

            // free the deleted entry
            free(entry->key);
            free(entry->value);
            free(entry);

            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;

        ++idx;
    }
}

void ht_dump(ht_t *hashtable)
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL)
        {
            continue;
        }

        printf("slot[%4d]: ", i);

        for (;;)
        {
            printf("%s=%s ", entry->key, entry->value);

            if (entry->next == NULL)
            {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}

int main(int argc, char **argv)
{
    ht_t *ht = ht_create();

    ht_set(ht, "name1", "em");
    ht_set(ht, "name2", "russian");
    ht_set(ht, "name3", "pizza");
    ht_set(ht, "name4", "doge");
    ht_set(ht, "name5", "pyro");
    ht_set(ht, "name6", "joost");
    ht_set(ht, "name7", "kalix");

    ht_dump(ht);

    return 0;
}
