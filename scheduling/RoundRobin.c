#include <stdio.h>  // Standard I/O library

int main() {
    int i, n, tq, flag;  // i=loop var, n=process count, tq=time quantum, flag=marks completion
    int at[10], bt[10], rem[10];  // Arrays: Arrival Time, Burst Time, Remaining Time
    int curTime;  // Tracks current time during scheduling
    float totalTat = 0, totalWt = 0;  // Total Turnaround & Waiting Time (for averages)

    // Input: Number of processes
    printf("Number of Proceses: ");
    scanf("%d", &n);
    int remain = n;  // Tracks remaining processes to execute

    // Input process details (AT, BT) and initialize remaining time
    for (int i = 0; i < n; i++) {
        printf("Process %d :-\n", i + 1);
        printf("AT: ");
        scanf("%d", &at[i]);  // Arrival Time
        printf("BT: ");
        scanf("%d", &bt[i]);  // Burst Time
        rem[i] = bt[i];      // Remaining Time = BT initially
    }

    // Input Time Quantum
    printf("Time Quantum: ");
    scanf("%d", &tq);

    // Print table header
    printf("\nPID \t AT \t BT \t CT \t TAT \t WT \n");
    printf("--- \t -- \t -- \t -- \t --- \t -- \n");

    // Round Robin Scheduling Logic
    for (curTime = 0, i = 0; remain != 0;) {
        // Case 1: Process finishes within time quantum
        if (rem[i] <= tq && rem[i] > 0) {
            curTime += rem[i];  // Advance time by remaining BT
            rem[i] = 0;         // Mark as fully executed
            flag = 1;           // Flag to indicate completion
        } 
        // Case 2: Process needs more time (partial execution)
        else if (rem[i] > 0) {
            rem[i] -= tq;      // Deduct time quantum
            curTime += tq;     // Advance time by tq
        }

        // If process just completed, calculate metrics
        if (rem[i] == 0 && flag == 1) {
            remain--;          // Decrement remaining process count
            flag = 0;          // Reset flag
            int pid = i + 1;   // Process ID
            int ct = curTime;  // Completion Time
            int tat = ct - at[i];  // Turnaround Time (CT - AT)
            int wt = tat - bt[i];  // Waiting Time (TAT - BT)
            totalTat += tat;  // Accumulate TAT
            totalWt += wt;     // Accumulate WT
            // Print process metrics
            printf("%d \t %d \t %d \t %d \t %d \t %d \n", pid, at[i], bt[i], ct, tat, wt);
        }

        // Move to next process (Round Robin logic)
        if (i == n - 1) {
            i = 0;  // Wrap around to first process
        } 
        // If next process has arrived, move to it
        else if (at[i + 1] <= curTime) {
            i++;
        } 
        // Else, restart from first process
        else {
            i = 0;
        }
    }

    // Print averages
    printf("\nAverage Waiting Time= %f\n", totalWt / n);
    printf("Avg Turnaround Time = %f", totalTat / n);

    return 0;
}