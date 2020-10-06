#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main (){
	while (clock() < 10){
		void *fill = malloc(10 * 1000 * 1000);
		memset(fill, 0, 10 * 1000 * 1000);
		sleep(1);
	}
	return 0;
}

/*
Output:

[1] 4938
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 0  0 398644 187828  24216 263432    6   27   238   123   73  220  4  1 91  4  0
 0  0 398644 187828  24216 263432    0    0     0     0   52  181  4  1 95  0  0
 0  0 398644 187828  24216 263432    0    0     0     0   69  172  5  1 94  0  0
 1  0 398644 187828  24224 263424    0    0     0    60   61  128  3  0 97  0  0
 0  0 398644 187828  24224 263432    0    0     0     0   59  160  3  2 95  0  0
 0  0 398644 187828  24224 263432    0    0     0     0   55  148  6  0 94  0  0
 0  0 398644 187828  24224 263432    0    0     0     0   68  162  5  0 95  0  0
 0  0 398644 187828  24224 263432    0    0     0     0   39   86  3  1 96  0  0
 0  0 398644 187828  24224 263432    0    0     0     0   58  168  4  0 96  0  0
 0  0 398644 187828  24224 263432    0    0     0     0   59  118  4  0 96  0  0
[1]+  Done                    ./ex2


'si' and 'so' fields are equal to zero because there is enough memory,
thus no files are swapped
*/