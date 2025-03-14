// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Global variable for word count (used by size function)
unsigned int word_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 20000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false (case insensitive)
bool check(const char *word)
{
    // Get hash value for the word
    int hash_value = hash(word);

    // Get hash value for the word
    node *ptr = table[hash_value];
    for (node *temp = ptr; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }
    // word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;

    // loop through character in a string until it reach the end.
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash += tolower(word[i]);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        printf("Fail to open dictionary\n");
        return false;
    }

    // Read each string in the file to buffer until its EOF (end of file)
    char buffer[LENGTH + 1];
    while (fscanf(f, "%s", buffer) != EOF)
    {
        // make a node for each words. if failed then close file and safely return false.
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(f);
            return false;
        }

        // Copy word from buffer to node
        strcpy(n->word, buffer);
        n->next = NULL;

        // send to function hash to return me an int
        unsigned int index = hash(buffer);

        // Insert node at beginning of linked list.
        // Store the word at that location
        n->next = table[index];
        table[index] = n;

        // Increment word count
        word_count++;
    }

    // Close the dictionary file
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // loop through the table
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        // while its not at the end of the table yet
        while (ptr != NULL)
        {
            // free it!
            node *temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    return true;
}
