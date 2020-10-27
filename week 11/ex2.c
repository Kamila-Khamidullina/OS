#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/types/FILE.h>

int main(){

	char n[1024];

	memset(n, '\0', sizeof(n));
	setvbuf(stdout, n, _IOLBF, 1024);

	fprintf(stdout, "H");
	sleep(1);
	fprintf(stdout, "e");
	sleep(1);
	fprintf(stdout, "l");
	sleep(1);
	fprintf(stdout, "l");
	sleep(1);
	fprintf(stdout, "o");
	sleep(1);

	return(0);
}