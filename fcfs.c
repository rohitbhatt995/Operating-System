#include<stdio.h>
#include <stdlib.h>
struct Process
{
    int pid,at,bt,ct,tat,wt,rt,st;
};
int compare (const void *p1, const void *p2)
{
    int a=((struct Process *)p1)->at;
    int b=((struct Process *)p2)->at;
    if (a<b)
        return -1;
    else
        return 1;
}
int main()
{
    int n;
    int st=0,sat=0,id=0,cl=0;
    float aat=0,att=0,c=0,t=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct Process p[n];
    printf("Enter the value of AT and BT\n");
    for(int i=0;i<n;i++)
    {
        printf("For Process %d\n",i+1);
        p[i].pid=i+1;
        scanf("%d %d",&p[i].at,&p[i].bt);
    }
    qsort ((void *)p, n, sizeof(struct Process), compare); 
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            p[i].ct=p[i].at+p[i].bt;
            p[i].st=p[i].at;
        }
        else if(p[i-1].ct<=p[i].at)
        {
            id+=p[i].at-p[i-1].ct;
            p[i].ct=p[i].at+p[i].bt;
            p[i].st=p[i].at;
        }
        else
        {
            p[i].ct=p[i-1].ct+p[i].bt;
            p[i].st=p[i-1].ct;
        } 
        p[i].tat= p[i].ct-p[i].at;
        p[i].wt= p[i].tat-p[i].bt;
        st+=p[i].wt;
        sat+=p[i].tat; 
        p[i].rt=p[i].st-p[i].at;
    }
    aat=(float)st/(float)n;
    att=(float)sat/(float)n;
    cl=p[n-1].ct-p[0].st;
    c=((float)(cl-id)/(float)cl)*100;
    t=(float)n/(float)cl;
 
    printf("\nProcess ID");
    printf("\tArraving Time");
    printf("\tBrust Time");
    printf("\tCompletion Time");
    printf("\tTotal time");
    printf("\tWaiting Time");
    printf("\tResponse Time\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p
        [i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    } 
    printf("\nTotal Turn Around Time: %d\n",sat);
    printf("Average: %f\n",att); 
    printf("Total Waiting Time: %d\n",st);
    printf("Average: %f\n\n",aat);
    printf("Cycle Length: %d\n",cl);
    printf("CPU utilisation: %f\n",c);
    printf("ThrorughPut: %f\n",t);
    return 0;
}