#include <stdio.h>
#define MAX 100

typedef struct {
    int pid;
    int at;    // Arrival Time
    int bt;    // Burst Time
    int tat;   // Turnaround Time
    int ct;    // Completion Time
    int wt;
    int flag; 
    int priority;            // Flag to indicate process completion (1 = completed)
    int initial;
    
} process;

int main() {
    int n, total_time = 0, completed = 0, min_index, min_priority;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    process p[n+1];
    process p1[n+1];
    
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
        printf("Enter the Priority of the process %d",i);
        scanf("%d",&p[i].priority);
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
        min_priority = 9999;
        min_index = -1;

        // Find process with minimum burst time that has already arrived and is not completed
        for (int i = 1; i <= n; i++) {
            if (p[i].at <= total_time && p[i].flag == 0 && p[i].priority < min_priority) {
                min_priority = p[i].priority;
                min_index = i;
            }
        }

        // If no process is available at the current time, increment total_time
        if (min_index == -1) {
            total_time++;
        } else {
            // Execute the selected process
            p[min_index].initial=total_time;
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
    //calculation of turn around time and waiting time
    for(int i=1;i<=n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    //  for(int i=1;i<=n;i++)
    //     {
    //         p1[i]=p[i];
    //     }
    //sorted on the basis of pid
         for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(p[i].pid>p[j].pid)
                {   process tmp=p[j];
                    p[j]=p[i];
                    p[i]=tmp;
                }
            }
        }
    
     for(int i=0;i<=20;i++)
        {
            printf("--");
        }
        printf("\n");
        printf("pid");
        printf("     ");
        printf("at");
        printf("     ");
        printf("bt");
        printf("     ");
        printf("tat");
        printf("     ");
        printf("wt");
        printf("\n");
        
        float avgtat=0;
        float avgwt=0;
        for(int i=1;i<=n;i++)
        {
            printf("%d",p[i].pid);
            printf("      ");
            printf("%d",p[i].at);
            printf("      ");
            printf("%d",p[i].bt);
            printf("      ");
            printf("%d",p[i].tat);
            printf("      ");
            printf("%d",p[i].wt);
            printf("      ");
            printf("\n");
            avgtat+=p[i].tat;
            avgwt+=p[i].wt;
            
        }
        //avgtat=avgtat/n;
        //avgwt=avgwt/n;
        
        printf("\n");
        printf("The average waiting time is %0.2f:",avgtat/n);
        printf("\n");
        printf("The average waiting time is %0.2f:",avgwt/n);
        printf("\n");
        
       //sorting on the bassi of intial time
       for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(p[i].initial>p[j].initial)
                {   process tmp=p[j];
                    p[j]=p[i];
                    p[i]=tmp;
                }
            }
        }
        
           for(int i=1;i<=n;i++)
        {

            printf("p%d--",p[i].pid);
            
        }
        printf("\n");
        
        for(int i=1;i<=n;i++)
        {
            printf("%d   ",p[i].initial);
            if(i==n)
            {
                printf("%d   ",total_time);
            }
        }
    return 0;
}
