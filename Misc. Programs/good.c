#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    unsigned int i;
    int count = 0;
    struct timeval tv;

    while (1)
    {
        for (i=0; i<10; i++)
        {
            gettimeofday(&tv, NULL);
            printf("%lu sec, %lu usec\n", tv.tv_sec, tv.tv_usec);
            printf("Get time of day command: ", gettimeofday(&tv,));
            printf("adjtime command: ", adjtime(&tv,));
        }

        count++;
        printf("round %d complete\n", count);
    }
    return 0;
} // End main