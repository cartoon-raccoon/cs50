// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a chained hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// 26^2 for the first two letters of each word
const unsigned int N = 26;

// Hash table
node *table[N];
int wordCount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //creating cursor to traverse list
    //indexed to the hash on the table
    node *tmp = table[hash(word)];

    if (strcasecmp(tmp->word, word) == 0)
    {
        return true;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // int l1 = (int) tolower(word[0]) - 97;
    // int l2 = (int) tolower(word[1]) - 97;
    // int digest = ((26 * l1) + l2);

    // return digest;
    int n = (int) tolower(word[0]) - 97;
    return n;
}

// Loads dictionary into hashtable, returning true if successful else false
// table[index] is the bucket
bool load(const char *dictionary)
{
    //declaring variables that we need
    FILE *file = fopen(dictionary, "r");
    char *dictWord = malloc(LENGTH);
    if (dictWord == NULL)
    {
        return false;
    }

    while (fscanf(file, "%s", dictWord) != EOF)
    {
        //creating node to be pointed to later
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, dictWord);
        wordCount++;

        //next points to start of linked list
        n->next = table[hash(dictWord)];
        table[hash(dictWord)] = n;
        //pointer in table points to n
    }

    //cleanup
    fclose(file);
    free(dictWord);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // creates two pointers to traverse the linked list and cancel its element without losing its address
    node *tmp;
    node *cursor;

    // repeats for every index in the table
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        cursor = table[i];
        tmp = cursor;

        // until the end of the list keeps freeing the memory allocated in load
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        free(cursor);
    }
    return true;
}
