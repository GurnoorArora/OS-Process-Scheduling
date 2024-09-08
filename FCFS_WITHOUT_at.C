#include<stdio.h>
//fcfs without arrival time
typedef struct
{
    int pid;
    int bt;
    int tat;
    int ct;
    int wt;
    int intial;
}process;
int main()
{
    int n;
    printf("enter the number of processes you want to enter:");
    scanf("%d",&n);
    process p[n+1];
    process p1[n+1];
    for(int i=1;i<=n;i++)
    {
        p[i].pid=i;
        printf("Burst Time of %d process:",i);
        scanf("%d",&p[i].bt);
        printf("\n");
    }
    //till this point our processes are sorted
    int total_time=0;
    for(int i=1;i<=n;i++)
    {
        //recording the initial reaction time for the process
        p[i].intial=total_time;
        //when we reach this point we can start the process
        total_time=total_time+p[i].bt;
        //this will be the completion time for the process ith
        p[i].ct=total_time;
        //we can calculate the turn arounnd time from this
        p[i].tat=p[i].ct;
        //till this we are done calculating turn around time
        //we now calculate waiting time that is waiting time=tat-burst time
        p[i].wt=p[i].tat-p[i].bt;
        //hence we calculated waiting time also here
    }
     for(int i=1;i<=n;i++)
        {
            p1[i]=p[i];
        }
        //sorting again on the basis of pid
        
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
     //printing table now
        for(int i=0;i<=20;i++)
        {
            printf("--");
        }
        printf("\n");
        printf("pid");
        printf("     ");
        printf("bt");
        printf("     ");
        printf("tat");
        printf("     ");
        printf("wt");
        printf("\n");
        
        //printing 
        float avgtat=0;
        float avgwt=0;
        for(int i=1;i<=n;i++)
        {
            printf("%d",p[i].pid);
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
        //printing gantt chart 
        for(int i=1;i<=n;i++)
        {

            printf("p%d--",p1[i].pid);
            
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d   ",p1[i].intial);
            if(i==n)
            {
                printf("%d   ",total_time);
            }
        }
        
        
        
        
}