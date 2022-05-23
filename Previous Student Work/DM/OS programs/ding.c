//Daniel Martinez, Lab 5, 3/17/21

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


sem_t key;
sem_t chopstick[5];

void * philosopher(void *);
void eat(int);

void * philosopher(void * num){
	int phil=*(int *)num;

	sem_wait(&key);
	printf("\nPhilosopher %d is thinking\n", (phil + 1));
	sem_wait(&chopstick[phil]);
	sem_wait(&chopstick[(phil+1)%5]);

	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d is done eating!\n", (phil + 1));

	sem_post(&chopstick[(phil+1)%5]);
	sem_post(&chopstick[phil]);
	sem_post(&key);
}

void eat(int phil){
	printf("\nPhilosopher %d is eating\n", (phil + 1));
}

int main(){
	int i,a[5];
	pthread_t tid[5]; //threads with the size of five philosophers
	
	sem_init(&key,0,4); //create keys
	
	for(i=0;i<5;i++){
		sem_init(&chopstick[i],0,1); //create chopsticks locks for solution
		}
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]); //create threads in a loop for algorithm
	}
	for(i=0;i<5;i++){
		pthread_join(tid[i],NULL); //join threads as usual at the end
		}
}
