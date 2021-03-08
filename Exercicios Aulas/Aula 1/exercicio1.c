#include <stdio.h>
int main(){
    int var1=5;
    char var2='a';
    int *ptr1= &var1;
    char *ptr2=&var2;
    *ptr2 = 'b';

    printf("var1 tem o enderenço %p e o valor %d\n", ptr1, var1);
    printf("var2 tem o enderenco %p e o valor %c\n", ptr2, *ptr2 );

    //Numero de bytes necessários para guardar variáveis de diferentes tipos
    //int ou int* necessitam de diferentes tamanhos, tal como char e char*
    printf("int : %ld\n", sizeof(int));
    printf("int*: %ld\n", sizeof(int *));
    printf("char: %ld\n", sizeof(char));
    printf("char*: %ld\n", sizeof(char *));

    //Mostra os endereços de memória onde estão guardados os valores ptr1,ptr2
    //pelo que quando adicionamos mostramos o próximo endereço onde será metido um inteiro (+ 4 bytes no endereço)
    printf("ptr1: %ld\n", ptr1);
    printf("ptr2: %ld\n", ptr2);
    printf("ptr1 + 1: %ld\n", ptr1 +1 );
    printf("ptr2 + 1: %ld\n", ptr2 + 1);

    printf("%d\n", *ptr1 +1);
    printf("%d\n", *ptr2 + 1);
}