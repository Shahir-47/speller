// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int totalwords = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //hashes the word and return an index number of the array table
    int element = hash(word);
    //traverse throuth the linked list until the end
    node *temp = table[element];
    while (temp != NULL)
    {
        if (strcasecmp(word, temp->word) != 0)
        {
            temp = temp->next;
        }
        else
        {
            return true;
        }
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // hash function source (http://www.cse.yorku.ca/~oz/hash.html)
    // why i chose this hash function (https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed)
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */
    }   
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *txtfile = fopen(dictionary, "r");
    if (txtfile == NULL)
    {
        printf("eror404 :( \n");
        return false;
    }
    //loads one word per time in the variable word
    char word[LENGTH + 1];
    while (fscanf(txtfile, "%s\n", word) != EOF)
    {
        //new node is created for each word and the adress of the node is stored in the pointer temp
        node *temp = malloc(sizeof(node));
        //copy the word into the newly created node
        strcpy(temp->word, word);
        //hash the word to obtain an index number corresponding to the hash table
        int element = hash(word);   
        //if hashtable element is empty it will insert it in the index number given by the hash function
        //else it will point towards the the node the array element was initally poiting to and then the array element would point to the new node  
        if (table[element] != NULL)
        {
            temp->next = table[element];
            table[element] = temp;
        }
        else
        {
            table[element] = temp;
            temp->next = NULL;
        }
        totalwords = totalwords + 1;
    }
    fclose(txtfile);
    return true;
    
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //number of words counted simultaneously as loading in the hash table
    return totalwords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //goes through each array
    for (int i = 0; i < N; i++)
    {
        //in each array it will follow the linked list untill the end
        //first variable will point which node to free and then save the address of it another variable and move to the next node
        //meanwhile the second variable will free the values and follow variable 1 as it keeps pointing to new value until the end of the limked list
        node *temp = table[i];
        while (temp != NULL)
        {
            node *temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
    }
    return true;
}
