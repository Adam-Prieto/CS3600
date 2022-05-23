
/* @CS3600
   @ Sample program fro Lab 5
   Program to understand semaphores in classic Reader-Writer Problem
   ------------------------------------------------------------------*/

#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y; //Semaphores
pthread_t tid;
pthread_t writerthreads[50],readerthreads[50];
int readercount = 0;

void *reader(void* param)
{
    sem_wait(&x); //P()
    readercount++;
    if(readercount==1)
        sem_wait(&y);
    sem_post(&x); //V()
    printf("%d reader in CS\n",readercount);
    sleep(3);
    sem_wait(&x);
    readercount--;
    if(readercount==0)
    {
        sem_post(&y);
    }
    sem_post(&x);
    printf("%d Reader leaving CS\n",readercount+1);
    return NULL;
}

void *writer(void* param)
{
    printf("Writer try to enter CS\n");
    sem_wait(&y);
    printf("Writer entered CS\n");
    sem_post(&y);
    printf("Writer leaving CS\n");
    return NULL;
}

int main()
{
    int n2,i;
    printf("Enter the number of readers:");
    scanf("%d",&n2);
    printf("\n");
    int n1[n2];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(i=0;i<n2;i++)
    {
        pthread_create(&writerthreads[i],NULL,reader,NULL);
        pthread_create(&readerthreads[i],NULL,writer,NULL);
    }
    for(i=0;i<n2;i++)
    {
        pthread_join(writerthreads[i],NULL);
        pthread_join(readerthreads[i],NULL);
    }

}