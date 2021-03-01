#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 5

struct ArrayStack {
    int top;
    int capacity;
    int *array;
};


// Creating an array stack
struct ArrayStack *CreateStack(){
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));  
    if(!S){
        return NULL;
    }
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));	// allocate an array of size 1 initially

    if(!S->array){
        return NULL;
    }
    return S;
}

// See if the stack is full, no more spots avaialable
int IsFullStack(struct ArrayStack *S){
    return (S->top == S->capacity-1);
}

// See if the stack is empty, all the spots avaialable
int IsEmptyStack(struct ArrayStack *S){
    return S->top == -1;
}

// Push function -> inserts in the top of the stack a new element
void Push(struct ArrayStack *S, int x){
    // No overflow in this implementation
    if(IsFullStack(S)){   
        printf("Overflow: Stack full");
        return;
   }
    S->array[++S->top] = x;
}

// Show the element that is in the top of the stack
int Top(struct ArrayStack *S){
    if(IsEmptyStack(S))     
     return INT_MIN;

    return S->array[S->top];
}

// Pop function -> removes the element that is in the top of the stack
int Pop(struct ArrayStack *S){
    if(IsEmptyStack(S)){  
        printf("Underflow: Stack empty");
        return INT_MIN;
    }

    return S->array[S->top--];
}

// Function to delete the stack
void DeleteStack(struct ArrayStack *S){
    if(S) {
        if(S->array) 
            free(S->array);
        free(S);
    }

    printf("Stack deleted.\n");
}

int main(){

    struct ArrayStack *s = CreateStack();
    Push(s, 10);
    Push(s, 1);
    Push(s, 11);
    Push(s, 2);
    //Push(s, 10);
    //Push(s, 50);


    //prints the elements of the stack (also takes them so when the cicle is over the stack is empty)
    while(!IsEmptyStack(s)){
        printf("%d\n", Pop(s));
    }

    DeleteStack(s);

    return 0;
}