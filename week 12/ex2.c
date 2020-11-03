#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

	int check = 0;
	char str[255];
	fgets(str, sizeof(str), stdin);

	if (argc > 1)
		if (strcmp(argv[1], "-a") == 0)
			check = 1;

	if (!check)
		for (int i = 1; i < argc; i ++) {
			FILE *file = fopen(argv[i], "w");
			fputs(str, file);
			fclose(file);
		}

	else
		for (int i = 2; i < argc; i ++) {
			FILE *file = fopen(argv[i], "a");
			fputs(str, file);
			fclose(file);
		}

	printf("%s", str);

	return 0;

}