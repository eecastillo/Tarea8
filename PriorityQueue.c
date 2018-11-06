#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum {False,True} Bool;
struct strPriorityQueue{
   Type* arr;
   int size;
}

PriorityQueue priorityqueue_create(DestroyFunc dF, CompareFunc cF, int capacity){
    PriorityQueue pq = (PriorityQueue)malloc(sizeof(struct strPriorityQueue));
    pq->arr=(Type)malloc(sizeof(Type)*capacity);
}
void priorityqueue_destroy(PriorityQueue pq);
int priorityqueue_size(PriorityQueue pq);
void priorityqueue_offer(PriorityQueue pq, Type t);
Type priorityqueue_peek(PriorityQueue pq);
Type priorityqueue_poll(PriorityQueue pq);

int parentIndex(int index);
int leftChildIndex(int index);
int rightChildIndex(int index);
Bool isValidIndex(PriorityQueue q, int index);
