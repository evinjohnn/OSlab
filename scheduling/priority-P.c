#include <stdio.h>      // Standard I/O functions
#include <limits.h>     // For INT_MAX (used in priority comparison)
#include <stdbool.h>   // For boolean data type (true/false)

// Global variables to track performance metrics
float totalTat = 0, totalWt = 0, idle = 0;  // Total Turnaround Time, Waiting Time, and CPU idle time

// Process structure definition
struct Process {
    int pid;     // Process ID
    int at;      // Arrival Time
    int bt;      // Burst Time
    int ct;      // Completion Time
    int pr;      // Priority (lower value = higher priority)
    int tat;     // Turnaround Time (CT - AT)
    int wt;      // Waiting Time (TAT - BT)
    int rem;     // Remaining Burst Time (for preemptive scheduling)
    bool finished;  // Flag to mark process completion
};

// Function to swap two processes (used in sorting)
void swap(struct Process *p1, struct Process *p2) {
    struct Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Sort processes by PID (ascending order, Bubble Sort)
void sortByPid(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].pid > p[j + 1].pid) {
                swap(&p[j], &p[j + 1]);  // Swap if current PID > next PID
            }
        }
    }
}

// Sort processes by Burst Time (ascending order, Bubble Sort)
void sortByBt(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].bt > p[j + 1].bt) {
                swap(&p[j], &p[j + 1]);  // Swap if current BT > next BT
            }
        }
    }
}

// Display process table with metrics
void displayProcess(struct Process p[], int n) {
    printf("\nPID \t AT \t BT \t PR \t CT \t TAT \t WT \n");
    printf("--- \t -- \t -- \t -- \t -- \t --- \t -- \n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n", 
               p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT: %f", totalTat / n);  // Avg Turnaround Time
    printf("\nAverage WT: %f\n", totalWt / n);   // Avg Waiting Time
}

// Preemptive Priority (SJF-Priority) Scheduling Algorithm
void sjfP(struct Process p[], int n) {
    int curTime = 0;      // Current simulation time
    int completed = 0;    // Count of completed processes

    while (completed != n) {
        int selected = -1;       // Index of the selected process
        int highestPr = INT_MAX; // Track highest priority (lower value = higher priority)

        // Find the highest-priority process that has arrived and not finished
        for (int i = 0; i < n; i++) {
            if (!p[i].finished && p[i].at <= curTime && p[i].pr < highestPr) {
                highestPr = p[i].pr;
                selected = i;
            }
        }

        if (selected == -1) {
            curTime++;  // No process available, CPU idle
            idle++;
        } else {
            p[selected].rem--;  // Execute 1 unit of the selected process
            curTime++;

            // Check if process has completed execution
            if (p[selected].rem == 0) {
                p[selected].ct = curTime;  // Completion Time
                p[selected].tat = p[selected].ct - p[selected].at;  // Turnaround Time
                p[selected].wt = p[selected].tat - p[selected].bt;  // Waiting Time

                // Update global totals
                totalTat += p[selected].tat;
                totalWt += p[selected].wt;

                p[selected].finished = true;  // Mark as completed
                completed++;
            }
        }
    }
}

// Sort processes by Completion Time (for Gantt Chart)
void sortByCt(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].ct > p[j + 1].ct) {
                swap(&p[j], &p[j + 1]);  // Swap if current CT > next CT
            }
        }
    }
}

// Display Gantt Chart
void ganttChart(struct Process p[], int n) {
    sortByCt(p, n);  // Sort by completion time
    printf("\nGantt Chart:---\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("| P-%d (%d-%d) |", p[i].pid, 0, p[i].ct);  // First process
        } else {
            printf(" P-%d (%d-%d) |", p[i].pid, p[i - 1].ct, p[i].ct);  // Subsequent processes
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process p[n];  // Array of processes

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].finished = false;
        printf("Process %d :-\n", i + 1);
        printf("AT: ");
        scanf("%d", &p[i].at);  // Arrival Time
        printf("BT: ");
        scanf("%d", &p[i].bt);  // Burst Time
        printf("Priority: ");
        scanf("%d", &p[i].pr); // Priority
        printf("\n");
        p[i].rem = p[i].bt;    // Initialize remaining time = BT
    }

    sjfP(p, n);         // Run Preemptive Priority Scheduling
    sortByPid(p, n);    // Sort by PID for display
    displayProcess(p, n);  // Show process table
    ganttChart(p, n);   // Show Gantt Chart

    return 0;
}