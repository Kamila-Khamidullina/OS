#include <stdio.h>
#include <pthread.h>

char a[20];
int pos, consumerSleeping, producerSleeping;
long long int t;

void *Consume(void *n){
	while(1){
		if(consumerSleeping)
			continue;
		if(pos == 0){
			consumerSleeping = 1;
			producerSleeping = 0;
			continue;
		}
		printf("%c", a[pos]);
		pos--;
	}
	pthread_exit(NULL);
	return NULL;
}

void *Produce(void *n){
	while(1){
		if(producerSleeping)
			continue;
		if (pos == 20){
			consumerSleeping = 0;
			producerSleeping = 1;
			printf("Done production with time %lld\n", t++);
			continue;
		}
		a[pos] = 'a' + pos;
		pos++;
	}
	pthread_exit(NULL);
	return NULL;
}

int main(){
	consumerSleeping = 1;
	pthread_t timeP, timeC;
	pthread_create(&timeP, NULL, Produce, NULL);
	pthread_create(&timeC, NULL, Consume, NULL);
	while(1);
	return 0;
}

//stopped at time 112648