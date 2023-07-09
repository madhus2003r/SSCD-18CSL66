#include<stdio.h>
#include<stdlib.h>
int main()
{
int MAX[10][10],need[10][10],alloc[10][10],avail[10],completed[10],safeSequence[10];
int p,r,i,j,process,count=0;
printf("enter the no of process: ");
scanf("%d",&p);
for(i=0;i<p;i++)
completed[i] = 0;
printf("enter the no of resources: ");
scanf("%d",&r);
printf("enter the max matrix for each process: ");
for(i=0;i<p;i++)
{
printf("for process %d: ",i+1);
for(j=0;j<r;j++)
scanf("%d",&MAX[i][j]);
}
printf("enter the alloction for each process: ");
for(i=0;i<p;i++)
{
printf("\n for process %d:",i+1);
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
}
printf("enter the available resources: ");
for(i=0;i<p;i++)
scanf("%d",&avail[i]);
for(i=0;i<p;i++)
for(j=0;j<r;j++)
need[i][j]=MAX[i][j]-alloc[i][j];
do{
printf("\n max matrix:\t allocation matrix:\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d",MAX[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf("%d",alloc[i][j]);
printf("\n");
}
process=-1;
for(i=0;i<p;i++)
{
if(completed[i]==0)
{
process=i;
for(j=0;j<r;j++)
{
if(avail[j]<need[i][j])
{
process=-1;
break;
}
}
}
if(process!=-1)
break;
}
if(process!=-1)
{
printf("\n process %d runs to completion",process+1);
safeSequence[count]=process+1;
count++;
for(j=0;j<r;j++)
{
avail[j]+=alloc[process][j];
alloc[process][j]=0;
MAX[process][j]=0;
completed[process]=1;
}
}
}
while(count!=p && process!=-1);
if(count==p)
{
printf("the system is in safe state\n");
printf("safe sequence:<");
for(i=0;i<p;i++)
printf("%d",safeSequence[i]);
printf(">\n");
}
else
printf("the system is in unsafe state");
}


