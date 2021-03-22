#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stackar.h"

//to compile
// compile on terminal first the stackar.c
// then compile parentesis.c
// then gcc -o parentesis parentesis.o stackar.o

bool ParentesisMatch1(char *s){
    int i; char ch;
    Stack st;

    st = CreateStack(10);

    for(i = 0; i <strlen(s); i++){
        if(s[i] == '('){
            Push( s[i], st);
        } else if(s[i] == ')'){
            if(IsEmpty(st)){
                return false;
            }
            ch = Pop(st);
        }
    }

    if(!IsEmpty(st)){
        return false;
    }

    return true;
}

int main(){
    char str[20] = "ad(f(d))sda()";

    printf("%s: %d\n",str, ParentesisMatch1(str));

}

