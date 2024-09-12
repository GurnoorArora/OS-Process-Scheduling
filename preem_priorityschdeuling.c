#include<stdio.h>

typedef struct{
    int pid;
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
    int flag;
    int initial;
    int priority;//for priority
}process;

int main()
{
    int n, total_time = 0, completed = 0, min_index, min_priority;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process p[n + 1];
    int gantt[100]; // Changed to an integer array
    
    for (int i = 1; i <= n; i++) {
        p[i].flag = 0;
    }
    for (int i = 1; i <= n; i++) {
        p[i].pid = i;
        printf("Enter the Priority for process %d: ",i);
        scanf("%d",&p[i].priority);
        printf("Enter the Arrival time for process %d: ", i);
        scanf("%d", &p[i].at);
        printf("Enter the Burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
        p[i].initial = p[i].bt; // Store the initial burst time
        
        printf("\n");
    }
    while(completed<n)
    {
        min_priority=9999;
        
        min_index=-1;
        for(int i=1;i<=n;i++)
        {
            if(p[i].at<=total_time && p[i].flag==0 && p[i].priority<min_priority)
            {
                min_priority=p[i].priority;
                min_index=i;
            }
        }
        if (min_index == -1) {
            total_time++; // Increment time if no process is found
        } else {
            total_time++;
            gantt[total_time] = p[min_index].pid; // Store the process ID in the Gantt chart
            p[min_index].bt--;
            if(p[min_index].bt==0)
            {
                completed++;
                p[min_index].ct=total_time;
                p[min_index].flag=1;
            }
    }

}
for (int i = 1; i <= n; i++) {
        p[i].tat = p[i].ct - p[i].at;           // TAT = CT - AT
        p[i].wt = p[i].tat - p[i].initial;      // WT = TAT - initial BT
    }
    
    
     for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].pid > p[j].pid) {
                process temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

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
}
