#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int response_time;
    bool first_run;
} Process;

void calculate_rr(Process processes[], int n, int quantum) {
    int current_time = 0;
    int completed = 0;
    int queue[MAX_PROCESSES];
    int front = 0, rear = 0;
    bool in_queue[MAX_PROCESSES] = {false};
    
    printf("\n=== Round Robin Scheduling ===\n");
    printf("Time Quantum: %d\n", quantum);
    printf("\nExecution Timeline:\n");
    
    // Add first arrived process to queue
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time == 0) {
            queue[rear++] = i;
            in_queue[i] = true;
        }
    }
    
    while (completed < n) {
        if (front == rear) {
            // Queue empty, advance time to next arrival
            current_time++;
            for (int i = 0; i < n; i++) {
                if (processes[i].arrival_time == current_time && !in_queue[i]) {
                    queue[rear++] = i;
                    in_queue[i] = true;
                }
            }
            continue;
        }
        
        int idx = queue[front++];
        Process *p = &processes[idx];
        
        // First time this process runs
        if (p->first_run) {
            p->response_time = current_time - p->arrival_time;
            p->first_run = false;
        }
        
        int exec_time = (p->remaining_time > quantum) ? quantum : p->remaining_time;
        
        printf("Time %d-%d: P%d\n", current_time, current_time + exec_time, p->pid);
        
        p->remaining_time -= exec_time;
        current_time += exec_time;
        
        // Add newly arrived processes to queue
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time &&
                processes[i].remaining_time > 0 &&
                !in_queue[i] && i != idx) {
                queue[rear++] = i;
                in_queue[i] = true;
            }
        }
        
        if (p->remaining_time > 0) {
            // Re-add to queue if not finished
            queue[rear++] = idx;
        } else {
            // Process completed
            p->completion_time = current_time;
            p->turnaround_time = p->completion_time - p->arrival_time;
            p->waiting_time = p->turnaround_time - p->burst_time;
            in_queue[idx] = false;
            completed++;
        }
    }
    
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    printf("---\t---\t---\t---\t---\t---\t---\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time,
               processes[i].response_time);
    }
}

void print_averages(Process processes[], int n) {
    float total_tat = 0, total_wt = 0, total_rt = 0;
    
    for (int i = 0; i < n; i++) {
        total_tat += processes[i].turnaround_time;
        total_wt += processes[i].waiting_time;
        total_rt += processes[i].response_time;
    }
    
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Response Time: %.2f\n", total_rt / n);
}

int main(int argc, char *argv[]) {
    int quantum = 2;
    
    if (argc > 1) {
        quantum = atoi(argv[1]);
        if (quantum <= 0) quantum = 2;
    }
    
    Process processes[] = {
        {1, 0, 5, 5, 0, 0, 0, 0, true},
        {2, 1, 4, 4, 0, 0, 0, 0, true},
        {3, 2, 2, 2, 0, 0, 0, 0, true},
        {4, 3, 1, 1, 0, 0, 0, 0, true}
    };
    int n = 4;
    
    printf("Round Robin (RR) Scheduling\n");
    printf("Preemptive scheduling algorithm\n");
    printf("Processes: %d\n", n);
    
    calculate_rr(processes, n, quantum);
    print_averages(processes, n);
    
    printf("\nNote: Round Robin provides fair CPU time to all processes\n");
    printf("      Performance depends on time quantum choice\n");
    
    return 0;
}

