#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;           // Process ID
    int arrival_time;  // Arrival Time (AT)
    int burst_time;    // Burst Time (BT)
    int waiting_time;  // Waiting Time (WT)
    int turnaround_time; // Turnaround Time (TAT)
    int completion_time; // Completion Time (CT)
} Process;

void calculate_fcfs(Process processes[], int n) {
    int current_time = 0;
    
    printf("\n=== FCFS Scheduling ===\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("---\t---\t---\t---\t---\t---\n");
    
    for (int i = 0; i < n; i++) {
        // If process hasn't arrived yet, wait for it
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        // Calculate times
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        current_time = processes[i].completion_time;
        
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

int main(int argc, char *argv[]) {
    Process processes[MAX_PROCESSES] = {
        {1, 0, 5, 0, 0, 0},
        {2, 1, 3, 0, 0, 0},
        {3, 2, 8, 0, 0, 0},
        {4, 3, 6, 0, 0, 0}
    };
    int n = 4;
    
    if (argc > 1) {
        printf("Reading from command line arguments...\n");
        // Format: pid,at,bt pid,at,bt ...
        // Example: 1,0,5 2,1,3 3,2,8 4,3,6
        n = 0;
        for (int i = 1; i < argc && n < MAX_PROCESSES; i++) {
            if (sscanf(argv[i], "%d,%d,%d",
                      &processes[n].pid,
                      &processes[n].arrival_time,
                      &processes[n].burst_time) == 3) {
                n++;
            }
        }
    }
    
    printf("First Come First Served (FCFS) Scheduling\n");
    printf("Non-preemptive scheduling algorithm\n");
    printf("Processes: %d\n", n);
    
    calculate_fcfs(processes, n);
    print_averages(processes, n);
    
    printf("\nNote: FCFS may suffer from convoy effect\n");
    printf("      (long processes block shorter ones)\n");
    
    return 0;
}

