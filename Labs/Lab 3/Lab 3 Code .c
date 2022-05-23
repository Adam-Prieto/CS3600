/*OBSEVATIONS
-with out a sleep cammand thread 1 will complete first, then thread 2.
-With a sleep command the threads will take turn printing, and the printing process is slower.
-All the funtions are void so you have to return NULL at the end.
-The factorial will change with different runs, depending on when num was passed onto it.
	so far it is only printing the factorial for 3 and 1
*/
// Juliet Smith and Adam Prieto


#include<pthread.h>
#include<stdio.h>

//Declaring global variable
static int num = 5;


//Thread function
void *DecendingThread(int arg){
    for(int i = num;i>1;i--){
     sleep(1);
     num = num - 1;
      printf("The value is: %d\n", num);
    }
    return NULL;
  }


void *factorial(int arg){
    int fact = 1;
    for(int i = 1;i <num;i++){
    sleep(1);
    fact = fact * i;
    }
    printf("The factorial is:  %d\n", fact);
    return NULL;
  }

int main(){
   //Thread variables declared
   pthread_t   p1, p2;
   num = 5;

   //Creating Thread by calling thread function and argument 2
   pthread_create(&p1, NULL,DecendingThread,1);
   pthread_create(&p2, NULL,factorial,2);

   sem_init(&semaphore, 0 ,1);

   //Join a thread
   pthread_join(p1,NULL);
   pthread_join(p2,NULL);
   //printf("%d \n",counter);

return 0;
}