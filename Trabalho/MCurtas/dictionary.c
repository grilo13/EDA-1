// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
#define N 100000000

// Hash table
node *table[N];
FILE *dict;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get the hash for the word
    unsigned int hash_value = hash(word);
    // Loop through the linked list (bucket) for the actual word
    node *head = table[hash_value];
    while (head != NULL)
    {
        if (strcasecmp(word, head->word) == 0)
        {
            return true;
        }
        else
        {
            head = head->next;
        }
    }
    return false;
}

void printfList(node *n){
    node *n1;

    for(n1 = n; n1 != NULL; n1 = n1->next){
        printf("%s ", n1->word);
    }
}

void printHash(){
    for(int i = 0; i < 66900; i++){
        printf("\n HashTable[%d]: ", i);
        printfList(table[i]);
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash the string into an integer
    unsigned int hash_value = 0;

    char *two = "2abcáàâãABCÁÀÂÃ";
    char *three = "3deféêDEFÉÊ";
    char *four = "4GHIghi";
    char *five = "5JKLjkl";
    char *six = "6MNOÕÓÔmnoõóô";
    char *seven = "7PQRSpqrs";
    char *eight = "8TUÚVtuúv";
    char *nine = "9WXYZwxyz";

    for (int index = 0; index < strlen(word); index++)
    { 
        if(strchr(two, word[index])!= NULL){
            hash_value = hash_value*10 + 2;

        }else if(strchr(three, word[index])!= NULL){
            hash_value = hash_value*10 + 3;

        }else if(strchr(four, word[index])!= NULL){
            hash_value = hash_value*10 + 4;

        }else if(strchr(five, word[index])!= NULL){
            hash_value = hash_value*10 + 5;

        }else if(strchr(six, word[index])!= NULL){
            hash_value = hash_value*10 + 6;
        
        }else if(strchr(seven, word[index])!= NULL){
            hash_value = hash_value*10 + 7;

        }else if(strchr(eight, word[index])!= NULL){
            hash_value = hash_value*10 + 8;

        }else if(strchr(nine, word[index])!= NULL){
            hash_value = hash_value*10 + 9;
        }

    }
    // Add it to a bucket within the hashtable
    hash_value = hash_value % N;
    return hash_value;
}

int accept_or_not(void){
    char c;
    scanf(" %c", &c);
    return c; //ASCII NUMBER
}

int search(int key, char *message){
    node *n1;
    node *n = table[key];
    if(n!=NULL){
        for(n1 = n; n1 != NULL; n1 = n1->next){
            printf("Sugestão: %s, aceita (s/n)?", n1->word);
            int i = accept_or_not();
            if(i == 115){
                strcat(message,  n1->word);
                return 0;
            }else{
                continue;
            }
        }
        return 1;
    }else{
        return -1;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open the dictionary
    dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Dictionary can not be opened.");
        return false;
    }

    // Load each word into the dictionary
    char word[LENGTH + 1];
    unsigned int hash_value = 0;

    // Not reaching the end of the dictionary
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Create a new node to be added
        node *new_node = malloc(sizeof(node));

        // When no empty memory exists
        if (new_node == NULL)
        {
            printf("No memory, failed to load the dictionary.\n");
            unload();
            return false;
        }
        // Create a hash value
        hash_value = hash(word);
        strcpy(new_node->word, word);

        // Insert the node at the beginning of the linked-list
        new_node->next = table[hash_value];
        table[hash_value] = new_node;
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return 0 if the file is not loaded
    if (dict == NULL)
    {
        return 0;
    }
    else
    {
        unsigned int size = 0;
        // Loop through the hashtable
        for (int index = 0; index < N; index++)
        {
            // Get access to the head of the bucket
            node *head = table[index];
            while (head != NULL)
            {
                size ++;
                head = head->next;
            }
        }
        return size;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Remove all nodes stored in the hashtable
    for (int index = 0; index < N; index++)
    {
        // Get access to the head of each bucket
        node *head = table[index];
        while (head != NULL)
        {
            // Keep the address of the current node
            node *temp = head;
            head = temp->next;
            // Free the node we just accessed
            free(temp);
        }
    }
    return true;
}