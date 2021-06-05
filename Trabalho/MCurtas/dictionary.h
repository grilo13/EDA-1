#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word

#define LENGTH 50

typedef struct node node;

bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
int accept_or_not(void);
int search(int key, char *message);

/*********help funtions **********/
void printfList(node *n);
void printHash();
/*********************************/

#endif // DICTIONARY_H