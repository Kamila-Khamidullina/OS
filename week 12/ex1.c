#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	FILE *f1 = fopen("/dev/random", "r");

	char randomString[21];

	for(int i = 0; i < 20; i++)
		randomString[i] = fgetc(f1);
	 
	randomString[20] = '\0';

	FILE *f2 = fopen("ex1.txt", "w");
	fprintf(f2, "%s\n", randomString);

	fclose(f1);
	fclose(f2);

	return 0;
}