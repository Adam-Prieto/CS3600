//Daniel Martinez
//March 5th, 2021
//Midterm Take Home Lab

#include<stdio.h>
#include<pthread.h>


static int n[20]; //Array size of 20
int user;         //Accept user Input for given number
int count = 0;    //Count set to zero of occurances

pthread_mutex_t lock; //Mutex Locking

//Population program
void *populate(int n[]){


	printf("\n\nRandom Populating: ");
	for(int i = 0; i < 20; i++){
		n[i] = rand() % 10;
	printf("%d ", n[i]);
	}
	
	return NULL;

}
///////////////////

void *find(int thread){
	
	pthread_mutex_lock(&lock); //Locking critical section
	
	int i = 0;
	for(i; i < 4; i++){
		if(n[i + thread] == user){ //Will find in array if given number is found, will sleep and increment count
			count++;
			sleep(4);
		}
	}
	
	pthread_mutex_unlock(&lock); //unlocking critical section

}



int main(int arc, char *argv[]){
	
	populate(n); //Call population program
	
	pthread_t t1, t2, t3, t4, t5; //Initlizing threads

	//Prompting user and grabbing data
	printf("\n\nWhat number do you want? ");
	scanf("%d", &user);
	printf("\nYou've entered: %d\n", user);
	//////////////////////////////////////
	
	//Creating Threads
	pthread_create(&t1, NULL, find, 0);
	pthread_create(&t2, NULL, find, 4);
	pthread_create(&t3, NULL, find, 8);
	pthread_create(&t4, NULL, find, 12);
	pthread_create(&t5, NULL, find, 16);
	/////////////////////////////////////
	/////////////////////////////////////
	//Joining Threads
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
	/////////////////////////////////////
	//Statements for what we found!
	if(count != 0){
		printf("\nWe found %d\n", count);
	}
	else{
		printf("\nWe found none!\n");
	}

	
	return(0);

}
