#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <inttypes.h>

int main() {

	char* string = "This is a nice day";
	size_t size = strlen(string) + 1;

  	FILE* f1 = fopen("ex1.txt", "r");
  	FILE* f2 = fopen("ex1.memcpy.txt", "w");

  	ftruncate(fileno(f2), size);

  	char* new1 = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(f1), 0);
  	char* new2 = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(f2), 0);

  	memcpy(new2, new1, size);
  	munmap(new2, size);

  	fclose(file1);
  	fclose(file2);

  	return 0;
}