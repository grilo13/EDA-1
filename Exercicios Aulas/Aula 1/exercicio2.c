#include <stdio.h>

int main(){
    int i, j, *p1, *p2, **pp1, **pp2;
    i=4;
    j=5;
    p1 = &i;
    p2 = &j;
    pp1 = &p2;
    pp2 = &p1;

    printf("%d\n", i);
    printf("%d\n", j);
    printf("%d\n", p1);
    printf("%d\n", p2);
    printf("%d\n", pp1);
    printf("%d\n", pp2);

    printf("%d\n", *p1);
    printf("%d\n", *p2);
    printf("%d\n", *pp1);
    printf("%d\n", *pp2);

    printf("%d\n", &i);
    printf("%d\n", &(*p1));
    printf("%d\n", *(&p1));


}

/* TABELA
Expressão:

-> p1 = 1000
-> p2 = 1007
-> pp1 = 1007
-> pp2 = 1000

-> i = 4
-> *p2 = 5 
-> &i = - 1974969552
-> &p2 = - 1974969552
-> *pp1 = -1308797164
-> *pp2 = -1308797168
-> &(*p1) = -1974969552
-> j = 5
-> *p1 = 4
-> *(&p1) = -1974969552
*/