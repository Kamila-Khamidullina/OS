#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	
	char* string = "This is a nice day";
	size_t size = strlen(string) + 1;

	FILE *f1 = fopen("ex1.txt", "w");

	ftruncate(fileno(f1), size - 1);

	int f2 = open("ex1.txt", O_RDWR);

	char* new = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, f2, 0);

	for (size_t i = 0; i < size; i++)
		new[i] = string[i];
	
	fclose(f1);
	fclose(f2);

	return(0);
}