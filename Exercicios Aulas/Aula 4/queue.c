#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "fatal.h"


#define MinQueueSize ( 5 )

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    ElementType *Array;
};

//Quantos elementos tem a fila
int size( Queue Q ){
    //(N-ini+fim) mod (%) N
    return ((Q->Capacity-Q->Front+Q->Rear) % Q->Capacity);
}

int successor( int i, Queue Q ){
    if(i == Q->Capacity-1){
        return 0;
    } else {
        return i+1;
    }

    return (i+1) % Q->Capacity;
}


Queue CreateQueue( int MaxElements ){
    Queue Q;

    if( MaxElements < MinQueueSize )
        Error( "Queue size is too small" );

    Q = malloc( sizeof( struct QueueRecord ) );
    if( Q == NULL )
        FatalError( "Out of space!!!" );

    Q->Array = malloc( sizeof( ElementType ) * MaxElements );
    if( Q->Array == NULL )
        FatalError( "Out of space!!!" );

    Q->Capacity = MaxElements;
    MakeEmptyQueue( Q );

    return Q;
}


void DisposeQueue( Queue Q ){
    if( Q != NULL ){
        free( Q->Array );
        free( Q );
    }
}


bool IsEmptyQueue( Queue Q ){

    return Q->Front == Q->Rear;
}


bool IsFullQueue( Queue Q ){

    return size(Q) == Q->Capacity - 1;
}



void MakeEmptyQueue( Queue Q ){
}


void Enqueue( ElementType X, Queue Q ){

    if(IsFullQueue(Q)){
        printf("Queue is already full.");
        return;
    }

    Q->Array[Q->Rear] = X;
    printf("%d\n",Q->Array[Q->Rear]);
    Q->Array[Q->Rear+=1];
}


ElementType Front( Queue Q ){
    return Q->Array[Q->Front];
}


ElementType Dequeue( Queue Q ){
    if(IsEmptyQueue(Q)){
        printf("Queue is empty\n");
    } else {
        int x = Q->Array[Q->Front];
        int suc = successor(Q->Array[Q->Front],Q);

        printf("Dequeued number = %d\n",x);

        return x;
    }
}

int main(){

    struct QueueRecord *queue = CreateQueue(10);

    Dequeue(queue);

    Enqueue(10,queue);
    Enqueue(20,queue);
    Enqueue(30,queue);

    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);

    return 0;
}

/*

Capacity = 10

Como saber se está cheia? Quando temos 9 elementos


front = 0, Rear = 0 ==> vazia
front = 0, Rear = 1 ==> 1 elemento, indice 0

front = 5; Rear = 5 ==> vazia
front  =5, Rear = 6 ==> 1 elemento, indice 5
front = 5, Rear = 9 ==> 4 elementos, indice 5,6,7,8

enqueue
front = 5, Rear = 0 ==> elementos, indice 5,6,7.8,9

enqueue, enqueue
front =5, Rear = 2 ==> elementos, indice 5 6,7,8,9,0.1

enqueue, enqueue
front = 5, Rear = 4 ==> elementos, indice 5,6,7,8,9,0,1,2,3

não podemos fazer mais enqueues, porque front = 5 e Rear = 5, logo iria assumir que estava vazia

*/
