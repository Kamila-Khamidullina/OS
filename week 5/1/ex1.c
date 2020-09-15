#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int number = 0;
void *createdThread(void *vargp){
	printf("Number %d\n", number);
	number++;
}

int main(void){
	pthread_t num;
	for (int i = 0; i < 3; i++){
		printf("Thread is created\n");
		pthread_create(&num, NULL, createdThread, NULL);
		pthread_join(num, NULL);
	}

	exit(0);
}