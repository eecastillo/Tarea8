#include "PriorityQueue.h"
#include <stdio.h>

//void DestroyFunc(){}
int compareInts(Type t1, Type t2) {
	int *i1 = (int*) t1;
	int *i2 = (int*) t2;
	return *i2 - *i1;
}

int main(){
    PriorityQueue pq = priorityqueue_create(NULL, compareInts, 15);
    int n1=2;
	int n2=6;
	int n3=3;
	int n4=9;
	int n5=7;
	int n6=4;
	

    priorityqueue_offer(pq, &n5);
	print(pq);

	//6 ser� izq de 9
	priorityqueue_offer(pq, &n3);
	print(pq);

	//60 ser� der de 9
	priorityqueue_offer(pq, &n1);
	print(pq);

	//5 ser� izq de 6
	priorityqueue_offer(pq, &n6);
	print(pq);

    priorityqueue_offer(pq, &n2);
	print(pq);

	//6 ser� izq de 9
	priorityqueue_offer(pq, &n4);
	print(pq);

	/*//60 ser� der de 9
	priorityqueue_offer(pq, &n4);
	print(pq);

	//5 ser� izq de 6
	priorityqueue_offer(pq, &n30);
	print(pq);*/


}