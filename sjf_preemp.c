#include <stdio.h>
#include <limits.h> // for INT_MAX

typedef struct {
    int pid;
    int at;    // Arrival Time
    int bt;    // Burst Time
    int tat;   // Turnaround Time
    int ct;    // Completion Time
    int wt;    // Waiting Time
    int flag;  // Flag to indicate process completion (1 = completed)
    int initial; // Store original burst time
} process;

int main() {
    int n, total_time = 0, completed = 0, min_index, min_bt;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process p[n + 1];
    int gantt[100]; // Changed to an integer array
    
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
        p[i].initial = p[i].bt; // Store the initial burst time
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

    while (completed < n) {
        min_bt = INT_MAX;
        min_index = -1;

        // Find the process with the minimum burst time that has arrived
        for (int i = 1; i <= n; i++) {
            if (p[i].at <= total_time && p[i].flag == 0 && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                min_index = i;
            }
        }

        if (min_index == -1) {
            total_time++; // Increment time if no process is found
        } else {
            total_time++;
            gantt[total_time] = p[min_index].pid; // Store the process ID in the Gantt chart
            p[min_index].bt--;

            if (p[min_index].bt == 0) {
                completed++;
                p[min_index].ct = total_time; // Set completion time
                p[min_index].flag = 1; // Mark as completed
            }
        }
    }

    // Calculation of Turnaround Time (TAT) and Waiting Time (WT)
    for (int i = 1; i <= n; i++) {
        p[i].tat = p[i].ct - p[i].at;           // TAT = CT - AT
        p[i].wt = p[i].tat - p[i].initial;      // WT = TAT - initial BT
    }

    // Sorting by process ID before displaying
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].pid > p[j].pid) {
                process temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    // Display table
    printf("\n");
    for (int i = 0; i <= 20; i++) {
        printf("--");
    }
    printf("\n");
    printf("pid     at      bt      tat     wt\n");

    float total_tat = 0;
    float total_wt = 0;
    
    for (int i = 1; i <= n; i++) {
        printf("%d       %d       %d       %d       %d\n", p[i].pid, p[i].at, p[i].initial, p[i].tat, p[i].wt);
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("\n");
    printf("The average turnaround time is %.2f\n", total_tat / n);
    printf("The average waiting time is %.2f\n", total_wt / n);
    
    // Display Gantt Chart
    printf("Gantt Chart:\n");
    for (int i = 1; i <= total_time; i++) {
        if (gantt[i] != 0) {
            printf("| P%d ", gantt[i]);
        } else {
            printf("| - "); // No process executed
        }
    }
    
    
    
    printf("|\n");
   

    return 0;
}
