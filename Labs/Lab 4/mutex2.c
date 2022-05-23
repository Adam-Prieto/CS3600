// Kero Lee, Adam Prieto, Christian Mudd
// CS3600 Lab 4 : File: mutex2.c
// Objective to understad locks in threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
//Run the program without locks and Identify the critical section and write below
/*


*/
//Modify the program with mutex lock to avoid the race condition

int arr[10];
static int inc;

void *incr(void* n) {

    inc = n;

    for(int i=0;i<10;i++)
    {
        sleep(2);
        //Complete the code here to increment array elements with variable inc
        arr[i] = arr[i] + inc;
        //sleep(2);

    }
}

int main() {
    pthread_t t1, t2;
    int i;
    for(i=0;i<10;i++)
    {
        arr[i]=1;
    }
//pthread_create(); //Complete thread creation to pass the value to be incremented in thread 1
    pthread_create(&t1, NULL, incr, (void*)2);
//pthread_create(); //Complete thread creation to pass the value to be incremented in thread 2
    pthread_create(&t2, NULL, incr, (void*)3);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    //print the array here
    for(int i=0;i<5;i++)
    {
        printf("%d\n",arr[i]);
    }

    exit(0);
}