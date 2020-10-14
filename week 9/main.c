#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int N = 1000;
    int pageReferences[N];
    FILE *file;
    file = fopen("C:\\Users\\roman\\CLionProjects\\lab 9\\Lab 09 input.txt", "r");
    for (int i = 0; i < N; i++)
        fscanf(file, "%d", &pageReferences[i]);
    fclose(file);

    int pf = 0, hit = 0, miss = 0, current = 0, filled = 0, new = 0;
    int frames[3] = {10, 50, 100};
    int hits[3], misses[3];
    for (int f = 0; f < 3; f++) {
        pf = frames[f];
        filled = 0;
        int pageFrames[pf], counter[pf];
        for (int l = 0; l < pf; l++){
            pageFrames[l] = 0;
            counter[l] = 0;
        }
        bool found;
        hit = miss = 0;
        for (int i = 0; i < N; i++) {
            found = false;
            current = pageReferences[i];
            for (int j = 0; j < filled; j++) {
                if (!found) {
                    if (current == pageFrames[j]) {
                        counter[j] = i;
                        found = true;
                        hit++;
                    }
                    else if (filled != pf) {
                        pageFrames[filled] = current;
                        counter[filled] = current;
                        found = true;
                        filled++;
                        miss++;
                    }
                }
            }
            if (!found && filled == 0){
                filled++;
                miss++;
                pageFrames[0] = current;
                counter[0] = i;
                found = true;
            }
            else if (!found) {
                miss++;
                int oldest = i;
                for (int l = 0; l < pf; l++)
                    if (counter[l] < oldest)
                        oldest = l;
                pageFrames[oldest] = current;
                counter[oldest] = i;
            }
        }
        hits[f] = hit;
        misses[f] = miss;
    }
    for (int i = 0; i < 3; i++)
        printf("%d frames: %d hits, %d misses, %.2f hit/miss ratio\n", frames[i], hits[i], misses[i], hits[i] * 1.0 / misses[i]);
    return 0;
}
