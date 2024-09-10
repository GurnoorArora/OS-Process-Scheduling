#include <stdio.h>
#define MAX 100

typedef struct {
    int pid;
    int at;    // Arrival Time
    int bt;    // Burst Time
    int tat;   // Turnaround Time
    int ct;    // Completion Time
    int flag;  // Flag to indicate process completion (1 = completed)
} process;

int main() {
    int n, total_time = 0, completed = 0, min_index, min_bt;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    process p[n+1];
    
    // Initializing flag values to 0 (indicating not executed yet)
    for (int i = 1; i <= n; i++) {
        p[i].flag = 0;
    }

    // Input Arrival Time and Burst Time for all processes
    for (int i = 1; i <= n; i++) {
        p[i].pid = i;
        printf("Enter the Arrival time for process %d: ", i);
        scanf("%d", &p[i].at);
        printf("Enter the Burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
        printf("\n");
    }

    // Sorting processes by Arrival Time
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].at > p[j].at) {
                process temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    // Main logic for Non-preemptive SJF
    while (completed < n) {
        min_bt = 9999;
        min_index = -1;

        // Find process with minimum burst time that has already arrived and is not completed
        for (int i = 1; i <= n; i++) {
            if (p[i].at <= total_time && p[i].flag == 0 && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                min_index = i;
            }
        }

        // If no process is available at the current time, increment total_time
        if (min_index == -1) {
            total_time++;
        } else {
            // Execute the selected process
            total_time += p[min_index].bt;
            p[min_index].ct = total_time;  // Completion time
            p[min_index].flag = 1;         // Mark process as completed
            completed++;
        }
    }

    // Output the completion time for each process
    for (int i = 1; i <= n; i++) {
        printf("Process %d - Completion time: %d\n", p[i].pid, p[i].ct);
    }

    return 0;
}
