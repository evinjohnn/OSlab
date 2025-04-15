#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


float totalTat = 0, totalWt = 0, idle = 0;;

struct Process{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	bool finished;
};


void swap(struct Process *p1, struct Process *p2){
	struct Process temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void sortByPid(struct Process p[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(p[j].pid > p[j+1].pid){
				swap(&p[j], &p[j+1]);
			}
		}
	}
}

void sortByBt(struct Process p[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(p[j].bt > p[j+1].bt){
				swap(&p[j], &p[j+1]);
			}
		}
	}
}


void displayProcess(struct Process p[], int n){
	printf("\nPID \t AT \t BT \t CT \t TAT \t WT \n");
	printf("--- \t -- \t -- \t -- \t --- \t -- \n");
	for(int i=0; i<n ; i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d \n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}
	
	printf("\nAverage TAT: %f", totalTat / n);
	printf("\nAverage WT: %f\n", totalWt / n);

}

void sjfNp(struct Process p[], int n){
	int curTime = 0;
	int completed  = 0;
	
	
	int shortestBT = INT_MAX;
	int selected = -1;
		
	
	while(completed != n){
		for(int i=0; i<n; i++){
			if(!p[i].finished){
				if(p[i].at <= curTime && p[i].bt <= shortestBT){
					selected = i;
					shortestBT = p[i].bt;
				}	
			}
		}
	
		if(selected == -1){
			idle++;
			curTime++; 
		}
		else{
			p[selected].ct = curTime + p[selected].bt;
			p[selected].tat = p[selected].ct - p[selected].at;
			p[selected].wt = p[selected].tat - p[selected].bt;
			
			curTime = p[selected].ct;
			totalTat += p[selected].tat;
			totalWt += p[selected].wt;
			p[selected].finished = true;
			completed++;
			shortestBT = INT_MAX;
		}
	
	}
}


void sortByCt(struct Process p[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(p[j].ct > p[j+1].ct){
				swap(&p[j], &p[j+1]);
			}
		}
	}
}

void ganttChart(struct Process p[], int n){
	sortByCt(p,n);
	printf("\nGantt Chart:---\n");
	for(int i=0; i<n; i++){
		if(i==0){
			printf("| P-%d (%d-%d) |", p[i].pid, 0, p[i].ct);
		}
		else{
			printf(" P-%d (%d-%d) |", p[i].pid, p[i-1].ct, p[i].ct);
		}
		
	}
	printf("\n");
}

int main(){

	
	int n;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	struct Process p[n];
	
	for(int i = 0; i<n ; i++){
		p[i].pid = i+1;
		p[i].finished = false;
		printf("Process %d :-\n" , i+1);
		printf("AT: ");
		scanf("%d", &p[i].at);
		printf("BT: ");
		scanf("%d", &p[i].bt);
		printf("\n");
		
	}
	
	sjfNp(p,n);
	sortByPid(p ,n);
	displayProcess(p, n);
	
	ganttChart(p, n);

	return 0;
}
