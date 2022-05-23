//***************************************************************************

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>



int myArray[40] = { 0,1,2,3,4,5,6,7,8,9,
                    10,11,12,13,14,15,16,17,18,19,
                    20,21,22,23,24,25,26,27,28,29,
                    30,31,32,33,34,35,36,37,38,39};


int arraySums[4] = { 0 };
int part = 0;

void* sumOfArrayElements(void* arg)
{

    // Each thread computes sum of 1/4th of array
    int threadNumber = part++;

    for (int i = (threadNumber * 10); i < (threadNumber + 1) * (10); i++)
        arraySums[threadNumber] += myArray[i];
} // End sumOfArrayElements

int main()
{


    // Create 4 threads
    pthread_t threads[4];
    for (int i = 0; i < 4; i++)
        pthread_create(&threads[i], NULL, sumOfArrayElements, (void*)NULL);

    // Wait for all threads to complete
    for (int i = 0; i < 4; i++)
        pthread_join(threads[i], NULL);

    // Get sum of sums
    int totalArray = 0;
    for (int i = 0; i < 4; i++)
        totalArray += arraySums[i];

    // Print result
    printf("Sum: %d\n", totalArray);

    return 0;
}
