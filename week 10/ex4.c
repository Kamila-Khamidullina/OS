#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
	DIR *file;
	file = opendir("/Users/kamila/Desktop/labs/Week 10/tmp");

	if (file != NULL){
		int n = 0;
		struct dirent *name[1001];
		struct dirent *point = readdir(file);

		while((point = readdir(file)) != NULL)
			name[++n] = point;

		(void)closedir(file);

		for(int i = 1; i < n + 1; i ++){
			for(int j = i + 1; j < n + 1; j ++)
				if(name[i]->d_ino > name[j]->d_ino){
					struct dirent * tmp;
					tmp = name[i];
					name[i] = name[j];
					name[j] = tmp;
				}

			if(i > 1)
				if(name[i]->d_ino == name[i-1]->d_ino)
					printf("%s %s\n", name[i]->d_name, name[i-1]->d_name);
		}
	}
}