# Operating Systems - FacePrep Lab Programs

This repository contains C programs for Operating Systems lab exercises sourced from FacePrep. The programs cover core OS concepts including CPU scheduling, deadlock avoidance, page replacement, and memory allocation.

---

## Programs

### faceprep_1.c — Round Robin CPU Scheduling Algorithm

Implements the Round Robin (RR) CPU scheduling algorithm. Accepts the number of processes, their Arrival Times (AT), Burst Times (BT), and a Time Quantum (TQ). The CPU rotates through processes in the ready queue, granting each a maximum of one TQ of execution time. Calculates Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT) for each process along with overall averages.

**Input:** Number of processes, Time Quantum, Arrival Time and Burst Time for each process  
**Output:** Average Turnaround Time, Average Waiting Time

---

### faceprep_2.c — Banker's Deadlock Avoidance Algorithm

Implements the Banker's Algorithm for deadlock avoidance. Accepts the number of processes and resource types, the Maximum Demand matrix, the currently Allocated resources matrix, and the Available resources vector. Computes the Need matrix and determines if the system is in a Safe State. If safe, displays the Safe Sequence; otherwise, indicates that a deadlock may occur.

**Input:** Number of processes, number of resource types, Allocation matrix, Max matrix, Available resources  
**Output:** Safe state status and Safe Sequence (if applicable)

---

### faceprep_3.c — LRU Page Replacement Algorithm

Implements the Least Recently Used (LRU) page replacement algorithm. Accepts a reference string and the number of frames. For each page request, determines whether it results in a Hit or a Fault. If a Fault occurs and all frames are full, replaces the page that was accessed least recently. Calculates the total number of Page Faults and Page Hits.

**Input:** Number of pages in reference string, reference string, number of frames  
**Output:** Total Page Faults, Total Page Hits

---

### faceprep_4.c — First Fit Contiguous Memory Allocation

Implements the First Fit memory allocation strategy. For each process, searches through memory blocks sequentially and allocates the first block that is large enough to satisfy the process size. Displays the block number, block size, and internal fragmentation for each allocation. Processes that cannot be allocated are reported accordingly.

**Input:** Number of memory blocks, block sizes, number of processes, process sizes  
**Output:** Allocation details and internal fragmentation per process

---

### faceprep_5.c — Best Fit Contiguous Memory Allocation

Implements the Best Fit memory allocation strategy. For each process, searches all available memory blocks and allocates the smallest block that is sufficient to satisfy the process size. This minimizes internal fragmentation compared to First Fit. Displays the block number, block size, and internal fragmentation for each allocation.

**Input:** Number of memory blocks, block sizes, number of processes, process sizes  
**Output:** Allocation details and internal fragmentation per process

---

## How to Compile and Run

```bash
gcc faceprep_1.c -o faceprep_1 && ./faceprep_1
```

Replace `faceprep_1` with the desired program number (1–5).

---

## Topics Covered

| File | Topic | Category |
|------|-------|----------|
| faceprep_1.c | Round Robin CPU Scheduling | CPU Scheduling |
| faceprep_2.c | Banker's Deadlock Avoidance | Deadlock Handling |
| faceprep_3.c | LRU Page Replacement | Memory Management |
| faceprep_4.c | First Fit Memory Allocation | Memory Management |
| faceprep_5.c | Best Fit Memory Allocation | Memory Management |
