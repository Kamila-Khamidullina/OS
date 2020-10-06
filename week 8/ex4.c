#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>

int main (){
	struct rusage usage;
	for (size_t i = 0; i < 10; ++i){
		void *fill = malloc(10 * 1000 * 1000);
		memset(fill, 0, 10 * 1000 * 1000);
		getrusage(RUSAGE_SELF, &usage);
		printf("Memory usage: %ld\n", usage.ru_maxrss);
		sleep(1);
	}
	return 0;
}