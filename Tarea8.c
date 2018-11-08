#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

//void DestroyFunc(){}
int compareInts(Type t1, Type t2) {
	int *i1 = (int*) t1;
	int *i2 = (int*) t2;
	return *i2 - *i1;
}

void Destroyfunc(Type t){
	int * pN = (int*) t;
	free(pN);
}

int main(){
    PriorityQueue pq = priorityqueue_create(Destroyfunc, compareInts, 15);
    int n1=2;
	int n2=6;
	int n3=3;
	int n4=9;
	int n5=7;
	int n6=4;
	

    priorityqueue_offer(pq, &n3);
	print(pq);

	//6 ser� izq de 9
	priorityqueue_offer(pq, &n2);
	print(pq);

	//60 ser� der de 9
	priorityqueue_offer(pq, &n6);
	print(pq);

	//5 ser� izq de 6
	priorityqueue_offer(pq, &n4);
	print(pq);

    priorityqueue_offer(pq, &n5);
	print(pq);

	//6 ser� izq de 9
	priorityqueue_offer(pq, &n1);
	print(pq);

	printf("el primer elemento es: %d\n",*(int*)priorityqueue_peek(pq));
	int size=priorityqueue_size(pq);
	printf("el tamano es: %d\n",size);

	for(int i=0;i<size;i++){
		printf("%d\n",priorityqueue_poll(pq));
		//print(pq);
	}

	priorityqueue_destroy(pq);
	printf("Destruido");
	/*//60 ser� der de 9
	priorityqueue_offer(pq, &n4);
	print(pq);

	//5 ser� izq de 6
	priorityqueue_offer(pq, &n30);
	print(pq);*/


}