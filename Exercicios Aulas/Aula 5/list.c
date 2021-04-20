#include "list.h"
#include <stdlib.h>
#include "fatal.h"


struct Node{
    ElementType Element;
    Position    Next;
};


List MakeEmpty( List L ){
    L=(List)malloc(sizeof(struct Node));
    L->Element = Header;
    L->Next = NULL;
    return L;
}

bool IsEmpty( List L ){
    return L->Next == NULL;
}

bool IsLast( Position P, List L ){
    return P->Next == NULL;
}

Position Find( ElementType X, List L ){
    Position P;

    P = L->Next;  /*Primeiro elemento*/
    while(P != NULL && P->Element != X){
        P = P->Next;
    }
    return P;
}


Position FindPrevious( ElementType X, List L ) {
    /* devolve posicao do elemento anterior
        se nao existir devolve o ultimo elemento
    */
    Position P;
    P = L;

    while(P->Next != NULL && P->Next->Element != X){
        P=P->Next;
    }
    return P;
}


void Insert( ElementType X, List L, Position P ) {
    Position Tmp = malloc(sizeof(struct Node));

    if (Tmp == NULL)
        FatalError("out of space!!!");

    Tmp->Element = X;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}

void Delete( ElementType X, List L ){
    Position P,tmp;

    P = FindPrevious(X,L);

    if(!IsLast(P,L)){  //se elemento existe
        tmp = P->Next;
        P->Next = tmp->Next;
        free(tmp);
    }
}


void DeleteList( List L ) {
    Position P, tmp;

    P = L->Next;
    L->Next = NULL;  /*primeiro elemento*/
    while( P != NULL){
        tmp = P->Next;  /*Proximo elemento*/
        free(P);
        P = tmp;
    }
}


Position Header( List L ) {
    return L;
}


Position First( List L ) {
    return L->Next;   //primeiro nó
}


Position Advance( Position P ) {
    return P->Next;
}


ElementType Retrieve( Position P ) {
    return P->Element;
}
