# CPU Scheduling Algorithms Implementation

## 📚 Table of Contents
1. [FCFS](#1-first-come-first-served-fcfs)
2. [SJF Non-Preemptive](#2-shortest-job-first-non-preemptive)
3. [SJF Preemptive (SRTF)](#3-shortest-remaining-time-first-srtf)
4. [Priority Non-Preemptive](#4-priority-scheduling-non-preemptive)
5. [Priority Preemptive](#5-priority-scheduling-preemptive)
6. [Round Robin](#6-round-robin)

---

## 1. First-Come First-Served (FCFS)

### 📝 Algorithm Description
```plaintext
1. Processes are executed in order of arrival
2. No preemption - runs to completion once started
3. Simple but suffers from convoy effect
🔧 Implementation Steps

void fcfs() {
    1. Sort all processes by arrival time (AT)
    2. Initialize:
       - current_time = 0
       - total_waiting = 0
       - total_turnaround = 0
    
    3. For each process in order:
       a. If process.AT > current_time:
          - CPU idle for (process.AT - current_time)
          - current_time = process.AT
       b. Calculate:
          - CT = current_time + process.BT
          - TAT = CT - process.AT
          - WT = TAT - process.BT
       c. Update totals:
          - total_waiting += WT
          - total_turnaround += TAT
       d. Advance clock:
          - current_time = CT
    
    4. Calculate averages:
       - avg_waiting = total_waiting / n
       - avg_turnaround = total_turnaround / n
}
⚠️ Limitations
Poor performance with varying burst times

High average waiting time when long processes arrive first

2. Shortest Job First (Non-Preemptive)
📝 Algorithm Description

1. Executes process with shortest burst time next
2. Non-preemptive - runs selected job to completion
3. Optimal for minimizing average waiting time
🔧 Implementation Steps

void sjf_nonpreemptive() {
    1. Initialize:
       - completed = 0
       - current_time = 0
       - All processes marked unfinished
    
    2. While (completed < total_processes):
       a. Find process with:
          - AT <= current_time
          - Smallest BT among ready processes
          - Not yet completed
       b. If no process found:
          - current_time++
          - Continue
       c. Else:
          - Execute full BT
          - Calculate CT, TAT, WT
          - Mark as completed
          - Update current_time
          - completed++
    
    3. Compute averages
}
💡 Key Insight
Requires knowledge of burst times beforehand

Starvation possible for long processes

3. Shortest Remaining Time First (SRTF)
📝 Algorithm Description

1. Preemptive version of SJF
2. Always executes job with shortest remaining time
3. More responsive than SJF
🔧 Implementation Steps

void srtf() {
    1. Initialize for all processes:
       - remaining_time = BT
       - completed = 0
    
    2. While (completed < total_processes):
       a. Find process with:
          - Smallest remaining_time > 0
          - AT <= current_time
          - Not completed
       b. If none:
          - current_time++
          - Continue
       c. Else:
          - Execute for 1 time unit
          - remaining_time--
          - current_time++
          - If remaining_time == 0:
             - Calculate metrics
             - Mark completed
             - completed++
}
🎯 Advantages
Minimizes average waiting time

More responsive to new short jobs

4. Priority Scheduling (Non-Preemptive)
📝 Algorithm Description

1. Executes highest priority (lowest number) job first
2. Non-preemptive - runs to completion
3. Priorities are static
🔧 Implementation Steps

void priority_nonpreemptive() {
    1. Sort processes by priority (ascending)
    
    2. Initialize:
       - current_time = 0
    
    3. For each process in priority order:
       a. Wait until arrival if needed
       b. Execute full BT
       c. Calculate metrics
       d. Update current_time
    
    4. Compute averages
}
⚠️ Caution
Starvation of low-priority processes

Priorities must be carefully assigned

5. Priority Scheduling (Preemptive)
📝 Algorithm Description

1. Preemptive priority-based scheduling
2. Can interrupt lower-priority jobs
3. More responsive than non-preemptive version
🔧 Implementation Steps

void priority_preemptive() {
    1. Initialize:
       - remaining_time = BT for all
       - completed = 0
    
    2. While (completed < total_processes):
       a. Find highest priority (lowest number) process:
          - AT <= current_time
          - remaining_time > 0
       b. If none:
          - current_time++
          - Continue
       c. Else:
          - Execute 1 time unit
          - remaining_time--
          - current_time++
          - If remaining_time == 0:
             - Calculate metrics
             - Mark completed
             - completed++
}
6. Round Robin
📝 Algorithm Description

1. Each process gets fixed time quantum (TQ)
2. Fair allocation but high context switching
3. No starvation
🔧 Implementation Steps

void round_robin() {
    1. Initialize:
       - ready_queue
       - remaining_time = BT for all
       - current_time = 0
    
    2. While (processes remain):
       a. Add arriving processes to queue
       b. If queue not empty:
          - Dequeue next process
          - Execute for min(TQ, remaining_time)
          - Update remaining_time
          - current_time += execution_time
          - If process finished:
             - Calculate metrics
          - Else:
             - Re-enqueue
       c. Else:
          - current_time++
}
⚙️ Configuration Note
Time quantum critically affects performance

Typical values: 10-100ms in real systems

