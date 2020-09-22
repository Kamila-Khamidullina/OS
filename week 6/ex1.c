#include<stdio.h>
#include <stdlib.h>

//assume that processes are given in the arrival time order

int main(){
    int n, count = 0, AT[1001], BT[1001], CT[1001], WT[1001], TAT[1001];
    float  sum_of_TAT = 0, sum_of_WT = 0;
    printf("Enter the number of processes: "); 
    scanf("%d", &n);

    for(int i = 1; i < n + 1; i++){
        printf("Enter the arrival time of the process #%d: ", i);
		scanf("%d", &AT[i]);
		printf("Enter the burst time of the process #%d: ", i);
		scanf("%d", &BT[i]);
    }

    for(int i = 1; i < n + 1; i++){
    	if (count - AT[i] > 0) WT[i] = count - AT[i];
        else WT[i] = 0;  
        TAT[i] = WT[i] + BT[i];
        if (count + BT[i] > AT[i] + BT[i]) count += BT[i];
        else count = AT[i] + BT[i]; 
        CT[i] = count;
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