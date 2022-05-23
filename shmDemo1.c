/*Shared memory.*/

/*Ranjidha 02/08/2022 */

/*  This header file is necessary for using shared
   memory constructs */

// To get the file running on mac, you must include 5 total header files.


#include <stdio.h>
//#include <sys/ipc.h>
#include <sys/shm.h> 

main()
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

    b[0]=10  ;
    //sleep(1);
                      
    printf("\tChild reads: %d\n",b[0]);
  
   shmdt(b); // This has to be last line before the end of the 'if'

}
else {
      //First run without the wait call, then remove the comment and run with wait call and see the difference.
      // wait(&status); // This is where the magic happens.

	a = (int *) shmat(shmid, 0, 0);

       //Assign number in Parent shared memory
       printf("\tparent reads: %d\n",a[0]);

	
	shmdt(a); // Like line 38, this has to be the last line before the brace.

	//shmctl(shmid, IPC_RMID, 0);
      }
}
