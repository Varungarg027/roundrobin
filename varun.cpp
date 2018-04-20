#include <stdio.h>
 int main() 
{
printf("ROUND ROBIN SCHEDULING");
int tq,pid[10],need[10],wt[10],tt[10],n,i,j,n1;
int ct[10], flag[10],total_tt=0,total_wt=0;
float a_wt,a_tt;
printf("\t\t ROUND ROBIN SCHEDULING");
printf("\n\nEnter the number of Processors \n");
scanf("%d",&n);
n1=n;
printf("\n Enter the Time_Quantum \n");
scanf("%d",&tq);
for(i=1;i<=n;i++)
{
printf("\n Enter the process ID %d arrival time ",i);
scanf("%d",&pid[i]);
printf("\n Enter the Burst Time of the process ");
scanf("%d",&ct[i]);
need[i]=ct[i];
}
for(i=1;i<=n;i++)
{
flag[i]=1;
wt[i]=0;
}
while(n!=0)
{
for(i=1;i<=n;i++)
{
if(need[i]>=tq)
{
for(j=1;j<=n;j++)
{
if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
wt[j]+=tq;
}
need[i]-=tq;
if(need[i]==0)
{
flag[i]=0;
n--;
}}
else
{
for(j=1;j<=n;j++)
{
if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
wt[j]+=need[i];
}
need[i]=0;
n--;
flag[i]=0;
}}}
for(i=1;i<=n1;i++)
{
tt[i]=wt[i]+ct[i];
total_wt=total_wt+wt[i];
total_tt=total_tt+tt[i];
}
a_wt=(float)total_wt/n1;
a_tt=(float)total_tt/n1;
printf("\n\n Process \t Process ID \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
for(i=1;i<=n1;i++)
{
printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pid[i],ct[i],wt[i],tt[i]);
}
printf("\n The average Waiting Time=%f",a_wt);
printf("\n The average Turn around Time=%f",a_tt); 
return 0;         
}
