#include <stdio.h>  // Standard input/output library

// Global variables to store total turnaround and waiting times
float totalTat = 0, totalWt = 0;

// Process structure definition
struct Process {
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
};

// Function to swap two processes
void swap(struct Process *p1, struct Process *p2) {
    struct Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Sort processes by arrival time (FCFS basis)
void sortByAt(struct Process p[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                swap(&p[j], &p[j+1]);  // Swap if current AT > next AT
            }
        }
    }
}

// Sort processes by completion time (for Gantt chart)
void sortByCt(struct Process p[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(p[j].ct > p[j+1].ct) {
                swap(&p[j], &p[j+1]);  // Swap if current CT > next CT
            }
        }
    }
}

// Display Gantt chart of process execution
void ganttChart(struct Process p[], int n) {
    sortByCt(p,n);  // Sort by completion time first
    printf("\nGantt Chart:---\n");
    for(int i=0; i<n; i++) {
        if(i==0) {
            printf("| P-%d (%d-%d) |", p[i].pid, 0, p[i].ct);  // First process
        }
        else {
            printf(" P-%d (%d-%d) |", p[i].pid, p[i-1].ct, p[i].ct);  // Subsequent processes
        }
    }
    printf("\n");
}

// Display process table with all metrics
void displayProcess(struct Process p[], int n) {
    printf("\nPID \t AT \t BT \t CT \t TAT \t WT \n");
    printf("--- \t -- \t -- \t -- \t --- \t -- \n");
    for(int i=0; i<n; i++) {
        printf("%d \t %d \t %d \t %d \t %d \t %d \n", 
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    
    // Calculate and display averages
    printf("\nAverage TAT: %f", totalTat / n);
    printf("\nAverage WT: %f\n", totalWt / n);
}

// FCFS scheduling algorithm implementation
void fcfs(struct Process p[], int n) {
    sortByAt(p,n);  // Sort processes by arrival time
    int curTime = 0;  // Current time in scheduler
    
    for(int i=0; i<n; i++) {
        if(curTime == 0) {
            // First process starts immediately
            p[i].ct = p[i].bt;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        else {
            // Subsequent processes start after previous completes
            p[i].ct = curTime + p[i].bt;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        curTime = p[i].ct;  // Update current time
        totalTat += p[i].tat;  // Accumulate totals
        totalWt += p[i].wt;
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];  // Array of processes
    
    // Input process details
    for(int i=0; i<n; i++) {
        p[i].pid = i+1;  // Assign process IDs
        printf("Process %d :-\n", i+1);
        printf("AT: ");
        scanf("%d", &p[i].at);  // Arrival Time
        printf("BT: ");
        scanf("%d", &p[i].bt);  // Burst Time
        printf("\n");
    }
    
    fcfs(p,n);  // Run FCFS scheduling
    displayProcess(p, n);  // Display results
    ganttChart(p, n);  // Show execution timeline

    return 0;
}