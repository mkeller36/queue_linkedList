#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN

typedef struct{
    int value;
    struct node *next;
} node;

typedef struct{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

int enqueue(queue *myQueue, int value){
    node * newNode = malloc(sizeof(node));  /*Create new node*/
    if(newNode == NULL) return -1;
    newNode->value = value;
    newNode->next = NULL;
    if(myQueue->tail != NULL){              /*If there is a tail, have tail point to new node*/
        myQueue->tail->next = newNode;
    }
    myQueue->tail = newNode;
    if(myQueue->head == NULL){              /*Make sure head is not "NULL"*/
        myQueue->head = newNode;
    }
    return 1;
}

int dequeue(queue *myQueue){
    if(myQueue->head == NULL) return QUEUE_EMPTY;   /*See if queue is empty*/
    node *tmp = myQueue->head;                      /*Create new node storing first element of queue*/
    int result = tmp->value;                        /*get value from first element*/
    myQueue->head = myQueue->head->next;            /*set head of queue to the next element*/
    if(myQueue->head == NULL){                      /*if head is null clear tail*/
        myQueue->tail == NULL;
    }
    free(tmp);                                      /*free memory*/
    return result;
}

int main(){
    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 420);
    enqueue(&q1, 69);
    enqueue(&q1, 666);
    enqueue(&q2, 1);
    enqueue(&q3, 2);
    enqueue(&q2, 3);
    enqueue(&q3, 4);
    enqueue(&q2, 5);
    enqueue(&q3, 6);

    int t;
    while((t = dequeue(&q1)) != QUEUE_EMPTY){
        printf("t = %d\n", t);
    }
        while((t = dequeue(&q2)) != QUEUE_EMPTY){
        printf("t = %d\n", t);
    }
        while((t = dequeue(&q3)) != QUEUE_EMPTY){
        printf("t = %d\n", t);
    }

}