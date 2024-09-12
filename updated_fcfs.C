// Online C compiler to run C program online
#include <stdio.h>
typedef struct
{
    int pid;
    int at;
    int bt;
    int tat;
    int ct;
    int flag;
    int wt;
    int initial;
}process;

int main() {
    int n,total_time=0,completed=0,min_index,min_at;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p[n+1];
    for(int i=1;i<=n;i++)
    {
        p[i].flag=0;
    }
    for (int i = 1; i <= n; i++) {
        p[i].pid = i;
        printf("Enter the Arrival time for process %d: ", i);
        scanf("%d", &p[i].at);
        printf("Enter the Burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
        printf("\n");
    }
    //sorting processes on arrival time
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(p[i].at>p[j].at)
            {
                process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    
    while(completed<n)
    {
         min_at=9999;
         min_index=-1;
         for(int i=1;i<=n;i++)
         {
             if(p[i].at<=total_time && p[i].flag==0 && p[i].at<min_at)
             {
                 min_at=p[i].at;
                 min_index=i;
             }
         }
         
         if(min_index==-1)
         {
             total_time++;
         }
         
         
         else
         {
             p[min_index].initial=total_time;
             total_time+=p[min_index].bt;
             p[min_index].flag=1;
             p[min_index].ct=total_time;
             p[min_index].tat=p[min_index].ct-p[min_index].at;
             p[min_index].wt=p[min_index].tat-p[min_index].bt;
             completed++;
         }
    }
    printf("\n");
    printf("\n");
     ////printing ganntt chart
        printf("\n");
        printf("0 ");
        for(int i=1;i<=n;i++)
        {
            printf("P%d %d ",p[i].pid,p[i].ct);
        }
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
    //printing the table
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
        printf("\n");
        printf("The average waiting time is %0.2f:",avgtat/n);
        printf("\n");
        printf("The average waiting time is %0.2f:",avgwt/n);
        printf("\n");
        
       
    

}
