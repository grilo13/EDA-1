#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
     int front, rear;
     int capacity;
     int size;
     int *array;
};

// Create an empty queue
struct Queue *createQueue(int capacity) {
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(!Q){
         return NULL;
    }
    Q->capacity = capacity;
    Q->front = Q->rear = -1;
    Q->size = 0;
    Q->array= malloc(Q->capacity * sizeof(int));

    if(!Q->array){
        return NULL;
    }

    return Q;
}

// Returns queue size
int size(struct Queue *Q) {
    return Q->size;
}

// Check's if Queue is empty or not
int isEmpty(struct Queue *Q) {
     // if the condition is true then 1 is returned else 0 is returned
     return (Q->size == 0);
}

// Check's if Queue is full or not
int isFull(struct Queue *Q) {
     // if the condition is true then 1 is returned else 0 is returned
     return (Q->size == Q->capacity);
}

// Returns Frnt Element of the Queue
int frontElement(struct Queue *Q) {
    return Q->array[Q->front];
}

// Returns the Rear Element of the Queue
int rearElement(struct Queue *Q) {
    return Q->array[Q->rear];
}

// Adding elements in Queue
void enqueue(struct Queue *Q, int data) {
    if(isFull(Q)){
        printf("Queue overflow (is full).\n");
    }
    else {
        Q->rear = (Q->rear+1) % Q->capacity;
        Q->array[Q->rear]= data;
        if(Q->front == -1)
            Q->front = Q->rear;
        Q->size += 1;
    }
}

// Removes an element from front of the queue
int dequeue(struct Queue *Q) {
    int data = INT_MIN; //or element which does not exist in Queue
    if(isEmpty(Q)){
        printf("Queue is empty\n");
        return data;
    }
    data = Q->array[Q->front];
    if(Q->front == Q->rear) {
        Q->front = Q->rear = -1;
        Q->size = 0;
    } else {
        Q->front = (Q->front+1) % Q->capacity;
        Q->size -= 1;
    }
    return data;
}

// Print elements to the queue
void print_elements(struct Queue *Q){

    for(int i = 0; i < size(Q); i++){
        printf("%d element is: %d\n",i,  Q->array[i]);
    }
}

// Delete all the elements in the queue

void deleteQueue(struct Queue *Q) {
    if(Q) {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}


//main to test the functions
int main(){

    struct Queue *Q;
    Q = createQueue(4);

    // Adding elements in Queue
    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 7);
    enqueue(Q, 5);

    //printing elements in the queue
    print_elements(Q);

    int deq1 = dequeue(Q);  
    int deq2 = dequeue(Q);

    printf("Dequeued element: %d\n", deq1);
    printf("Dequeued element: %d\n", deq2);

    print_elements(Q);  

    int front_element = frontElement(Q);
    int last_element = rearElement(Q);

    printf("Front element: %d\nRear Element: %d\n", front_element, last_element);

    // Printing size of Queue
    printf("\nSize of queue : %d\n", size(Q));

    return 0;
}