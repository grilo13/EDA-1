#include <stdio.h>

int horasMin(int min, int *horas, int*minutos){
    *horas = min / 60;
    *minutos = (min % 60);

    if(*horas >= 24){
        return 1;
    } else {
        return 0;
    }
}

int main(){

    int i;
    int min = 568;
    int *horas;
    int *minutos;
    int a;

    printf("Insira o total de minutos: ");
    scanf("%d", &a);

    int valor = horasMin(a,&horas, &minutos);

    if(valor == 1){
        printf("%d minutos correspondem a %dh:%dmin; é superior a um dia.", min, horas, minutos);
    } else {
        printf("%d minutos correspondem a %dh:%dmin; não é superior a um dia.", min, horas, minutos);
    }

    return 0;
}