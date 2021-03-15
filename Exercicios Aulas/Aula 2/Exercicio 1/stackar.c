#include "stackar.h"
#include "fatal.h"
#include <stdlib.h>


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )


struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};



Stack CreateStack( int MaxElements )
{
    Stack S;

	if( MaxElements < MinStackSize )
		Error( "Stack size is too small" );

	S = malloc( sizeof( struct StackRecord ) );
	if( S == NULL )
		FatalError( "Out of space!!!" );

	S->Array = malloc( sizeof( ElementType ) * MaxElements );
	if( S->Array == NULL )
		FatalError( "Out of space!!!" );
	S->Capacity = MaxElements;
	MakeEmpty( S );

	return S;
}


void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );
    }
}


int IsEmpty( Stack S )
{
	return S->TopOfStack == -1;
}


int IsFull( Stack S )
{
	return (S->TopOfStack == S->Capacity-1);
}


void MakeEmpty( Stack S )
{
	S->TopOfStack == EmptyTOS;
}


void Push( ElementType X, Stack S )
{
	if(IsFull(S)){
		printf("Overflow: Stack already full.");
		return;
	}

	S->Array[++S->TopOfStack] = X;   //++ tem de ser antes, se for depois coloca numa posicao que ainda não existe
	printf("%d",S->Array[S->TopOfStack]);
}

ElementType Top( Stack S )
{    
	
	if(IsEmpty(S))     
     return -1;

    return S->Array[S->TopOfStack];
}


ElementType Pop( Stack S )
{
	if(IsEmpty(S)){  
        printf("Underflow: Stack empty");
        return -1;
    }

    S->Array[S->TopOfStack--];
}

int main(){

	struct StackRecord *s = CreateStack(10);
	Push(15,s);
	Push(16,s);
	Push(17,s);
	Pop(s);
    return 0;
}