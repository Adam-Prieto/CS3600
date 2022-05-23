#include<stdio.h>
#include<pthread.h>


static int n = 10;


//Thread Function

void *factorial(int n){

	unsigned long long fact = 1;

	if(n < 0){
		return(0);
		}else{
		
	for(int i = 1; i <= n; i++){
		
		fact *= i;
	
		}
	}

	printf("\nFactorial: %d \n", fact);
	
	
	
	return NULL;

}

void *mythreadCollatz(int n){

	
	int i;
		while(n != 1){
		if(n%2==0){
			n = n/2;
			printf("Collatz: %d \n", n);	

		}
		else{
			n = (3*n) + 1;
			printf("Collatz: %d \n", n);
		}
	
	}

	
	return NULL;

}

int main(int arc, char *argv[]){

	

	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, mythreadCollatz, n);
	
	sleep(5);
	
	pthread_create(&t2, NULL, factorial, n);

	pthread_join(t1, NULL);
	
	pthread_join(t2, NULL);
	
	return(0);

}
