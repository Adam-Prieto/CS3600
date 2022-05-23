#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){

	pid_t pid;
	int x = atoi(argv[1]);
	
	if(x < 0 || x == 0){
		printf("Only Positive Integers!\n");
		exit(0);
	}
	
	pid = fork();
	
	if(pid == 0){
	printf("\nChild: \n");
	printf("%d \n", x);
		while((int)x != 1){
			if((int)x % 2 == 0){
			x /= 2;
			printf("%d \n", (int)x);
			}
			else{
			x = (x * 3) + 1;
			printf("%d \n", (int)x);
			}

		}
		printf("Parent: Done \n");
		wait(pid);
	}

	return 0;

}
