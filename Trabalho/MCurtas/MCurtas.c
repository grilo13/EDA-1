// Implements a spell-checker

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

#define ARR_SIZE 45
#define BUFSIZE 1000000

// Undefine any definitions
#undef calculate
#undef getrusage

// Prototype
double calculate(const struct rusage *b, const struct rusage *a);

int main(int argc, char *argv[])
{   
    char message[ARR_SIZE] = "Mensagem: ";
    char word[ARR_SIZE];
    char buff[BUFSIZE];

    int key = -1;

    // Check for correct number of args
    if (argc != 2)
    {
        printf("FORMATO: ./MCurtas dicionario.txt\n");
        return 1;
    }

    // Structures for timing data
    struct rusage before, after;

    // Benchmarks
    double time_load = 0.0, time_size = 0.0, time_unload = 0.0;

    // Determine dictionary to use
    char *dictionary = argv[1];

    // Load dictionary
    getrusage(RUSAGE_SELF, &before);
    bool loaded = load(dictionary);
    getrusage(RUSAGE_SELF, &after);

    // Exit if dictionary not loaded
    if (!loaded)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    // Calculate time to load dictionary
    time_load = calculate(&before, &after);

    // Determine dictionary's size
    getrusage(RUSAGE_SELF, &before);
    unsigned int n = size();
    getrusage(RUSAGE_SELF, &after);

    // Calculate time to determine dictionary's size
    time_size = calculate(&before, &after);

    // Report benchmarks
    printf("\nWORDS IN DICTIONARY:  %d\n", n);
    printf("TIME IN load:         %.2f\n", time_load);
    printf("TIME IN size:         %.2f\n", time_size);

    //printHash();

    // Success

    printf("\nHELLO! \nWELCOME TO THE NEW T9 TECNOLOGY - TEXT ON 9 KEYS\n");
    printf(" _______________________________\n");
    printf("|                               |\n");
    printf("|  0: LOG OUT                   |\n");
    printf("|  1: FINISH YOUR TEXT MESSAGE  |\n");
    printf("|  2: a b c á à â ã ç           |\n");
    printf("|  3: d e f é ê                 |\n");
    printf("|  4: g h i í                   |\n");
    printf("|  5: j k l                     |\n");
    printf("|  6: m n o ó ô õ               |\n");
    printf("|  7: p q r s                   |\n");
    printf("|  8: t u v ú                   |\n");
    printf("|  9: w x y z                   |\n");
    printf("|_______________________________|\n");
    printf("\n** Escreva a sua mensagem **\n");
    

    while(key != 1){

        scanf("%d", &key);

        if(key == 0){
            printf("Deseja sair da aplicação (s/n)?");

            int decision = accept_or_not();

            if(decision == 115){
                return 0;
            }else{
                continue;
            }

        }else if(key == 1){
            break;
        }

        int i = search(key, message);

        if(i == 1){
            printf("Não existem mais sugestões; introduza a palavra do teclado.\n");
            scanf("%s\n", word);
            strcat(message, word);
            strcat(message," ");

        }else if(i == 0){
            strcat(message," ");
            
        }else if(i == -1){
            printf("Não existe a palavra no dicionário, insira a palavra no teclado.\n");
            scanf("%s\n", word);
            strcat(message, word);
            strcat(message," ");

        }
    }
    
    puts(message);

    return 0;
}

// Returns number of seconds between b and a
double calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}


/*
    printf("\nHELLO! \nWELCOME TO THE NEW T9 TECNOLOGY - TEXT ON 9 KEYS\n");
    printf(" _______________________________\n");
    printf("|                               |\n");
    printf("|  0: LOG OUT                   |\n");
    printf("|  1: FINISH YOUR TEXT MESSAGE  |\n");
    printf("|  2: a b c á à â ã ç           |\n");
    printf("|  3: d e f é ê                 |\n");
    printf("|  4: g h i í                   |\n");
    printf("|  5: j k l                     |\n");
    printf("|  6: m n o ó ô õ               |\n");
    printf("|  7: p q r s                   |\n");
    printf("|  8: t u v ú                   |\n");
    printf("|  9: w x y z                   |\n");
    printf("|_______________________________|\n");
    printf("\n** Escreva a sua mensagem **\n");
    */
