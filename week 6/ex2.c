#include<stdio.h>
#include <stdlib.h>
 
int n, count = 0, in = 0; AT[1001], BT[1001], CT[1001], WT[1001], TAT[1001], BT2[1001];
float  sum_of_TAT = 0, sum_of_WT = 0;

int Next(int count){
    int min = 1001, index = -1;
    for(int i = 1; i < n + 1; i++)
        if(count >= AT[i] && BT2[i] > 0 && BT[i] < min){ 
            min = BT[i];
            index = i;
        }
    return index;
}

int main(){
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(int i = 1; i < n + 1; i++){
        printf("Enter the arrival time of the process #%d: ", i);
		scanf("%d", &AT[i]);
		printf("Enter the burst time of the process #%d: ", i);
		scanf("%d", &BT[i]);
		BT2[i] = BT[i];
    }

    while(in < n){
        int index = Next(count);
        if(index != -1){
            BT2[index]--;
            if(BT2[index] == 0){
                CT[index] = count + 1;
                in++;
            }
        }  
        count++;
    }
    
    for(int i = 1; i < n + 1; i++){
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        sum_of_TAT += TAT[i];
        sum_of_WT += WT[i];
    }
    
    float av_TAT = sum_of_TAT / n;
	float av_WT = sum_of_WT / n;

    for (int i = 1; i < n + 1; i++)
		printf("Process #%d\t AT: %d\t BT: %d\t CT: %d\t TAT: %d\t WT: %d\t\n\n", i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
	printf("Average TAT: %f\n", av_TAT);
	printf("Average WT: %f\n", av_WT);

    return 0;
}