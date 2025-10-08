#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    bool completed;
} Process;

void calculate_sjf(Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    
    printf("\n=== SJF Scheduling (Non-preemptive) ===\n");
    printf("Execution Order: ");
    
    while (completed < n) {
        int shortest_idx = -1;
        int shortest_bt = __INT_MAX__;
        
        // Find process with shortest burst time among arrived processes
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed &&
                processes[i].arrival_time <= current_time &&
                processes[i].burst_time < shortest_bt) {
                shortest_bt = processes[i].burst_time;
                shortest_idx = i;
            }
        }
        
        if (shortest_idx == -1) {
            // No process has arrived yet, advance time
            current_time++;
            continue;
        }
        
        Process *p = &processes[shortest_idx];
        printf("P%d ", p->pid);
        fflush(stdout);
        
        p->completion_time = current_time + p->burst_time;
        p->turnaround_time = p->completion_time - p->arrival_time;
        p->waiting_time = p->turnaround_time - p->burst_time;
        p->completed = true;
        
        current_time = p->completion_time;
        completed++;
    }
    
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("---\t---\t---\t---\t---\t---\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }
}

void print_averages(Process processes[], int n) {
    float total_tat = 0, total_wt = 0;
    
    for (int i = 0; i < n; i++) {
        total_tat += processes[i].turnaround_time;
        total_wt += processes[i].waiting_time;
    }
    
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
}

int main(void) {
    Process processes[] = {
        {1, 0, 6, 0, 0, 0, false},
        {2, 1, 8, 0, 0, 0, false},
        {3, 2, 7, 0, 0, 0, false},
        {4, 3, 3, 0, 0, 0, false},
        {5, 4, 4, 0, 0, 0, false}
    };
    int n = 5;
    
    printf("Shortest Job First (SJF) Scheduling\n");
    printf("Non-preemptive scheduling algorithm\n");
    printf("Processes: %d\n", n);
    
    calculate_sjf(processes, n);
    print_averages(processes, n);
    
    printf("\nNote: SJF gives minimum average waiting time\n");
    printf("      but may cause starvation of longer processes\n");
    
    return 0;
}

