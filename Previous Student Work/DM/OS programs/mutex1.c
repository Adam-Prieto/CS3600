// CS3600 Lab 4 : File: mutex2.c
//Objective to understad locks in threads
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int arr[5];


void *incr(int n){

  pthread_mutex_lock(&mutex1); // comment out
 
  int k = 0;

  for(k = 0; k < 5; k++){
  	arr[k] += n;
  	printf("%d ", arr[k]);
  	sleep(2);
  
  }

 
    printf("\n");
  
  pthread_mutex_unlock(&mutex1); // comment out
}



int main() {
	
	int i;
	for(i = 0; i < 5; i++){
	arr[i] = 1;
	}
	
	printf("Initial Array: ");
		for(int i = 0; i < 5; i++){
  			printf("%d ", arr[i]);
  		}
	printf("\n");
	
  pthread_t t1, t2; //Initlizing the threa
  
 pthread_create(&t1, NULL, incr, 2);
 pthread_create(&t2, NULL, incr, 3);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
  exit(0); 
}
