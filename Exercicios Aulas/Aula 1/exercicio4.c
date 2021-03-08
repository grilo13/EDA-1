#include <stdio.h>

int *vmaior(int *a, int *b){
    if(*a > *b){
        return a;
    } else {
        return b;
    }
}

int main(){

    int i;
    int x = 43, y= 65;

    int *maior = vmaior(&x,&y);

    printf("Maior: endereco=%ld, valor=%ld\n", maior, *maior);

    return 0;
}