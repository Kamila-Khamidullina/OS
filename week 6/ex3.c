#include<stdio.h>
#include <stdlib.h>
 
int main(){
    int n, q, in = 0, count = 0, AT[1001], BT[1001], CT[1001], WT[1001], TAT[1001], BT2[1001];
    float  sum_of_TAT = 0, sum_of_WT = 0;
    printf("Enter the number of processes: "); 
    scanf("%d", &n);

    for(int i = 1; i < n + 1; i++){
        printf("Enter the arrival time of the process #%d: ", i);
		scanf("%d", &AT[i]);
		printf("Enter the burst time of the process #%d: ", i);
		scanf("%d", &BT[i]);
		BT2[i] = BT[i];
    }

    printf("Enter the quantum number: ");
    scanf("%d", &q);

    while(in < n){
        int check = 0;
        for(int i = 1; i < n + 1; i++){
            if(AT[i] <= count && BT2[i] > 0){  
                check = 1;
                if(BT2[i] > q){ 
                    BT2[i] -= q;
                    count += q; 
                } 
                else{
                    count += BT2[i];  
                    CT[i] = count;
                    BT2[i] = 0;
                    in++;
                }
            }
        }
        if (!check) count++;
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