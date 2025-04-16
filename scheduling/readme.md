1. First-Come First-Served (FCFS) Scheduling Algorithm
Input:

Number of processes (n)

For each process:

Process ID (pid)

Arrival Time (at)

Burst Time (bt)

Data Structures:

Array of Process structures

Global variables:

totalTat (Total Turnaround Time)

totalWt (Total Waiting Time)

Steps:

Initialization:

Read process details

Sort processes by arrival time (at)

Scheduling:

Initialize current_time = 0

For each process in order:
a. If process.at > current_time:

CPU idle until process arrives

current_time = process.at
b. Execute process to completion:

process.ct = current_time + process.bt

process.tat = process.ct - process.at

process.wt = process.tat - process.bt
c. Update totals:

totalTat += process.tat

totalWt += process.wt
d. current_time = process.ct

Output:

Display process table (pid, at, bt, ct, tat, wt)

Calculate and display averages:

avgTat = totalTat/n

avgWt = totalWt/n

2. Shortest Job First - Non-Preemptive (SJF-NP)
Input:

Number of processes (n)

For each process:

pid, at, bt

finished (initialized to false)

Data Structures:

Process array

Global: totalTat, totalWt, idle

Steps:

Initialization:

Read process details

Set all processes as unfinished

Scheduling Loop:

Initialize current_time = 0, completed = 0

While completed < n:
a. Find process with:

Smallest bt

at ≤ current_time

finished == false
b. If no process found:

current_time++

idle++
c. Else:

process.ct = current_time + process.bt

process.tat = process.ct - process.at

process.wt = process.tat - process.bt

Update totals

Mark as finished

completed++

current_time = process.ct

Output: Same as FCFS

3. Shortest Job First - Preemptive (SJF-P/SRTF)
Input:

Number of processes (n)

For each process:

pid, at, bt

rem (initialized to bt)

finished (initialized to false)

Steps:

Initialization:

Read processes

Initialize rem = bt

Scheduling Loop:

current_time = 0, completed = 0

While completed < n:
a. Find process with:

Smallest rem

at ≤ current_time

!finished
b. If none:

current_time++

idle++
c. Else:

Execute 1 unit:
rem--
current_time++

If rem == 0:
Calculate metrics
Mark finished
completed++

Output: Same as above

4. Priority Scheduling - Non-Preemptive
Additional Input:

Priority (pr) for each process
(Lower value = higher priority)

Steps:

Initialization:

Read processes including priority

Sort by priority (ascending)

Scheduling:

current_time = 0

For each process in priority order:
a. Wait until arrival if needed
b. Execute to completion
c. Calculate metrics
d. Update current_time

Output: Same format

5. Priority Scheduling - Preemptive
Additional Data:

rem initialized to bt

Steps:

Initialization:

Read processes with priorities

Initialize rem = bt

Scheduling Loop:

While not all completed:
a. Find highest priority (lowest pr) ready process
b. If none: idle++
c. Else:

Execute 1 unit

rem--

If rem == 0:
Calculate metrics
Mark completed

Output: Same format

6. Round Robin (RR)
Additional Input:

Time Quantum (tq)

Steps:

Initialization:

Read processes

Initialize rem = bt

Create ready queue

Scheduling:

current_time = 0

While queue not empty:
a. Get next process
b. Execute for min(tq, rem):

rem -= time_used

current_time += time_used
c. If rem == 0:

Calculate metrics
d. Else:

Re-add to queue

Output: Same format
