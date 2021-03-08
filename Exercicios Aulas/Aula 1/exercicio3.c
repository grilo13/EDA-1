#include <stdio.h>

void ordena(int *a, int *b, int *c){

    //guardar os valores para poder substituir depois
    int aux = *a;  //aux = 3
    int aux1 = *b; //aux1 = 5
    int aux2 = *c; //aux2 = 2
    

   if (*a > *b){
       if (*b > *c){
           *a = aux2;
           *c = aux;
       }else{
           if (*a > *c){   //a > c > b
               *b = aux2;
               *c = aux;
               *a = aux1;
           }else{    //b > c > a
               *c = aux1;
               *b = aux2;
           }
       }                                              
   }else{
       if (*b > *c){
           if (*a > *c){    // b > a > c 
               *c = aux1;
               *b = aux;
               *a = aux2;
           }else{   //b > c > a
               *c = aux1;
               *b = aux2;
               *a = aux;
           }
       }else{   // c > b > a
          return;
       }                                          
   }                                     
}

int main(){

    int i;
    int x = 43, y= 65, z = 17;

    //passando os argumentos como &x, passamos os endereços de memória dessas variáveis
    //e na função maior, o que fazemos é alterar o valor das variáveis nesses endereços de memória
    //se fosse i = maior(x,y,z), print(x) ia dar 3, porque nao iamos conseguir mudar a variavel na funcao
    //sabendo o endereço de memória, podemos substituir o valor nessa mesma posição
    ordena(&x,&y,&z);

    printf("%d %d %d", x,y,z);

    return 0;
}