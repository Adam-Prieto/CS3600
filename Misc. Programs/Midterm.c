/* @CS3600

   @ Takehome program outline

   @ 03/03/22

   Do not delete the given outline code, you can add as much you need

   @Your name: Adam Prieto

   @Time taken for completing the program: ~22 hours

----------------------------------------------------------*/

#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<pthread.h>

#include<semaphore.h>

// Semaphore creation
sem_t semaphore1;
sem_t semaphore2;


int readCounter = 1;
int decrementCounter = 0;
int writeCounter = 1;


pthread_t tid;

pthread_t writerthreads[50],readerthreads[50];




void *reader(void* param)

{
    // Correct Reader Method

    printf("%d reader in CS\n", readCounter++);
    decrementCounter++;
    sleep(1);

    // I COMMENTED THIS LINE OUT SO THAT MY
    // OUTPUT MATCHES THE EXPECTED OUTPUT
    // BUT I DID NOT DELETE THE LINE
    //printf("Hello from thread %d\n", readCounter);

    printf("%d Reader leaving CS\n", decrementCounter--);

    // Semaphore variable 1
    sem_wait(&semaphore1);

    return NULL;

} // End *reader

void *writer(void* param)

{
    // Correct writer method

    sleep(1);
    printf("Writer [%d] writing in CS\n", writeCounter++);

    // Semaphore variable 2
    sem_wait(&semaphore2);

    return NULL;

} // End *writer


int main()

{
    // Initial variables
    int r1,w1,i,j;

    // Semaphore initialization
    sem_init(&semaphore1, 0 ,1);
    sem_init(&semaphore2, 0 ,1);

    printf("Enter the number of readers:");

    scanf("%d",&r1);

    printf("Enter the number of writers:");

    scanf("%d",&w1);

    printf("\n");


    // Create reader threads
    for(i=0;i<r1;i++)
    {

        pthread_create(&readerthreads[i],NULL,reader,NULL);
    } // End for

    // Create writer threads
    for(j=0;j<w1;j++)
    {

        pthread_create(&writerthreads[j],NULL,writer,NULL);

    } // End for



    for(i=0;i<r1;i++)
    {
        pthread_join(readerthreads[i],NULL);
    } // End for

    for(j=0;j<w1;j++)
    {
        writeCounter += 1;
        pthread_join(writerthreads[j],NULL);
    } // End for

    // Free memory of semaphores
    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);

    return 0;
} // End main