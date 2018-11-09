#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

struct strPriorityQueue{
   Type* arr;
   int size;
   int capacity;
   DestroyFunc dF;
   CompareFunc cF;
};

Bool isValidIndex(PriorityQueue pq, int index){
    if(pq==NULL || index>=pq->size) return False;
    return True;
}
int parentIndex(int index){
    //if(!isValidIndex(index)) return -2;
  
    return(index-1)/2;
}
int leftChildIndex(int index){
    //if(!isValidIndex(index)) return -3;
    return 2*index+1;
}
int rightChildIndex(int index){
    //if(!isValidIndex(index)) return -4;
    return 2*index+2;
}


PriorityQueue priorityqueue_create(DestroyFunc dF, CompareFunc cF, int capacity){
    PriorityQueue pq = (PriorityQueue)malloc(sizeof(struct strPriorityQueue));
    pq->arr=(Type*)malloc(sizeof(Type)*capacity);
    pq->size=0;
    pq->capacity=capacity;
    pq->cF=cF;
    pq->dF=dF;
}
void priorityqueue_destroy(PriorityQueue pq){
    if(pq == NULL) return;

    for(int i=0;i<pq->capacity;i++){
        pq->dF(pq->arr[i]);
    }
    free(pq->arr);
    free(pq);
}
int priorityqueue_size(PriorityQueue pq){
    if(pq == NULL) return -1;
    return pq->size;
}
void priorityqueue_offer(PriorityQueue pq, Type t){
    if(pq->size==pq->capacity-1){
        Type* temp=(Type*)realloc(pq->arr,sizeof(Type)*pq->capacity*2);
        if(temp!=NULL){
            pq->arr= temp;
        }
        pq->capacity*=2;
    }
    pq->arr[pq->size]= t;
    int pindex=parentIndex(pq->size);
    int index=pq->size;
    pq->size++;
    
    while(pq->cF(pq->arr[pindex],pq->arr[index])<0){
        Type datatemp = pq->arr[pindex];
        pq->arr[pindex]=pq->arr[index];
        pq->arr[index]=datatemp;
        index=pindex;
        pindex=parentIndex(index);
    }
}
Type priorityqueue_peek(PriorityQueue pq){
    if(pq == NULL || pq->size==0) return NULL;
    return pq->arr[0];

}
Type priorityqueue_poll(PriorityQueue pq){
    if(pq == NULL || pq->size==0) return NULL;
    Type temp = pq->arr[0];
    pq->dF(pq->arr[0]);
    pq->arr[0]=pq->arr[pq->size-1];
    pq->size--;
    printf("1\n");
    int e=0;
    int c=0;
    while((pq->cF(pq->arr[e],pq->arr[leftChildIndex(e)])>0||pq->cF(pq->arr[e],pq->arr[rightChildIndex(e)])>0) && e<pq->size-1){
        printf("indice %d\n",e);
        
        if(pq->cF(pq->arr[e],pq->arr[leftChildIndex(e)])>0){  
            c=leftChildIndex(e);
            printf("2\n");
            Type datatemp = pq->arr[e];
             printf("2.5\n");
            pq->arr[e]=pq->arr[c];
           
            pq->arr[c]=datatemp;
            
            e=c;
            printf("3\n");
            
        }
        else if(pq->cF(pq->arr[e],pq->arr[rightChildIndex(e)])>0){
            c=rightChildIndex(e);
            printf("4\n");
            Type datatemp = pq->arr[e];
            pq->arr[e]=pq->arr[c];
            pq->arr[c]=datatemp;
            e=c;
            printf("5\n");
        }
        printf("hijo %d\n",c);
    }
    return temp;
}



void print(PriorityQueue pq){
    for(int i=0;i<pq->size;i++){
        printf("%d ",*(int*)pq->arr[i]);
    }
    printf("\n");
}