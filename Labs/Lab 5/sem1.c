#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define NUM 1000000
int cnt = 0;

void * Count(void * a)
{
    int i, tmp;
    for(i = 0; i < NUM; i++)   
    {
        tmp = cnt;      /* copy the global cnt locally */
        tmp = tmp+1;    /* increment the local copy */
        cnt = tmp;      /* store the local value into the global cnt */ 
    }
}

int main(int argc, char * argv[])
{
//    pthread_t tid1, tid2;
//
//    pthread_create(&tid1, NULL, Count, NULL);
//
//    pthread_create(&tid2, NULL, Count, NULL);
//
//    pthread_join(tid1, NULL);        /* wait for the thread 1 to finish */
//
//    pthread_join(tid2, NULL);        /* wait for the thread 2 to finish */
//


    if (cnt < 2 * NUM) {
        printf("\n BOOM! cnt is [%d], should be %d\n", cnt, 2*NUM);
    }
    else {
        printf("\n OK! cnt is [%d]\n", cnt);
    }

    pthread_exit(NULL);

}
