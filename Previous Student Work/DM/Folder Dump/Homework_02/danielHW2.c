#include<stdio.h>
#include<pthread.h>



static int sum = 0;
static int n[40];


void *populate(int n[]){

	for(int i = 0; i < 40; i++){
	n[i] = i + 1;
	}
	return NULL;

}

void *matho(int n[], int a, int thread){
	
	int matho = a*thread;
	int prematho = matho;
	matho -= 10;
	for(int i = matho; i < prematho; i++){
		sum = sum + n[i];
	}

}



void *sumOfArray(int n[]){

	pthread_t t1, t2, t3, t4;

	int calc = sizeof(n) * 5;
	printf("Array Size right now: %d\n", calc);
	int four = calc/4;
	printf("Size of Array divided by four: %d\n", four);
	
	pthread_create(&t1, NULL, matho(n,four,1), NULL);
	pthread_create(&t2, NULL, matho(n,four,2), NULL);
	pthread_create(&t3, NULL, matho(n,four,3), NULL);
	pthread_create(&t4, NULL, matho(n,four,4), NULL);
	

}



int main(int arc, char *argv[]){

	populate(n);
	
	sumOfArray(n);
	
	printf("Sum: %d\n", sum);


}
