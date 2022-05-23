#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>	
#include <unistd.h>
#include <sys/wait.h>


int main()
{
	int shmid,status;
	int *a, *b;
	int i;

	shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT);

	
	if (fork() == 0) {

		/* Child Process */

		 b = (int *) shmat(shmid, 0, 0);

		//Write a for loop to read two values from shared memory
		
		shmdt(b);

	}
	else {
		/* Parent Process */

		a = (int *) shmat(shmid, 0, 0);

		a[0] = 0; a[1] = 1;

		//Write a for loop to update the shared memory values a[0]=a[0]+a[1] and a[1]=a[0]+a[1]
		
		/* each process should "detach" itself from the 
		   shared memory after it is used */

		shmdt(a);

		shmctl(shmid, IPC_RMID, 0);
	}

 return 0;
}

