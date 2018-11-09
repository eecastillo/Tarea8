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
    /*int n1=2;
	int n2=6;
	int n3=3;
	int n4=9;
	int n5=7;
	int n6=4;*/
    
    int n1 = 8;
    int n2 = 12;
    int n3 = 9;
    int n4 = 24;
    int n5 = 23;
    int n6 = -8;
    int n7 = 33;
    int n8 = 4;
    int n9 = 6;
    int n10 = -8;
    int n11 = 10;
    int n12 = 12;
    int n13 = 9;
    int n14 = 6;
    int n15 = 15;
    int n16 = 3000;
    int n17 = -8;
    int n18 = 17;
	

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
	
	priorityqueue_offer(pq, &n7);
	print(pq);
	
	priorityqueue_offer(pq, &n8);
	print(pq);
	
	priorityqueue_offer(pq, &n9);
	print(pq);
		
	priorityqueue_offer(pq, &n10);
	print(pq);
			
	priorityqueue_offer(pq, &n11);
	print(pq);
				
	priorityqueue_offer(pq, &n12);
	print(pq);
					
	priorityqueue_offer(pq, &n13);
	print(pq);
	
	priorityqueue_offer(pq, &n14);
	print(pq);
	
	priorityqueue_offer(pq, &n15);
	print(pq);
			
	priorityqueue_offer(pq, &n16);
	print(pq);
				
	priorityqueue_offer(pq, &n17);
	print(pq);
					
	priorityqueue_offer(pq, &n18);
	print(pq);
	
	printf("Capacidad: %d\n", capacidad(pq));
	
	printf("el primer elemento es: %d\n",*(int*)priorityqueue_peek(pq));
	int size=priorityqueue_size(pq);
	printf("el tamano es: %d\n",size);

	for(int i=0;i<size-1;i++){
		print(pq);
		printf("%d\n",*(int*)priorityqueue_poll(pq));
	}
	//print(pq);
	priorityqueue_destroy(pq);
	printf("Destruido");
	/*//60 ser� der de 9
	priorityqueue_offer(pq, &n4);
	print(pq);

	//5 ser� izq de 6
	priorityqueue_offer(pq, &n30);
	print(pq);*/


}