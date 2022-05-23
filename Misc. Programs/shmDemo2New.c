/*Shared memory.*/

// This code works as expected.


/*Ranjidha 02/08/2022 */

/*  This header file is necessary for using shared
   memory constructs */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int shmid,status;
int *a, *b;
int i,num;

shmid = shmget(IPC_PRIVATE, 1*sizeof(int), 0777|IPC_CREAT);

/* Accept number here i parent*/

num=35;

if (fork() == 0) {

/* Create Child Process */

    b = (int *) shmat(shmid, 0, 0); //Shared memory reading value

    for (i=0; i<10; i++){
        sleep(1);
        printf("\t\t\t Child reads: %d,%d\n",b[0],b[1]);


    }
    printf("\tChild reads: %d\n",b[0]);

   shmdt(b);

}
else {
      //First run without the wait call, then remove the comment and run with wait call and see the difference.
      // wait(&status);

	a = (int *) shmat(shmid, 0, 0);
    a[0] = 0;
    a[1] = 1;



    for(i=0; i<10; i++)
    {
        sleep(1);
        a[0] = a[0] + a[1];
        a[1] = a[0] + a[1];
        printf("Parent writes: %d,%d\n", a[0], a[1]);
    }
    wait(&status);
       //Assign number in Parent shared memory
       printf("\tparent reads: %d\n",a[0]);


	shmdt(a);

	shmctl(shmid, IPC_RMID, 0);
      }
}
