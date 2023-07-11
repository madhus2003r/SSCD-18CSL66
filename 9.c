#include<stdio.h>
#include<stdlib.h>
void FIFO(char[],char[],int,int);
void LRU(char[],char[],int,int);
int main()
{
int ch,YN=1,i,l,f;
char F[10],s[25];
printf("\n\n\t enter the number of empty frames:");
scanf("%d",&f);
printf("\n\n\t enter the length of string:");
scanf("%d",&l);
printf("\n\n\t enter the string:");
scanf("%s",s);
for(i=0;i<f;i++)
F[i]=-1;
do
{
printf("\n\n\t ******MENU******");
printf("\n\n\t 1FIFO\n\n\t2:LRU\n\n\t4:EXIT");
printf("\n\n\t enter the choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:for(i=0;i<f;i++)
F[i]=-1;
FIFO(s,F,l,f);
break;
case 2:for(i=0;i<f;i++)
F[i]=-1;
LRU(s,F,l,f);
break;
case 3:exit(0);
}
printf("\n\t Do you want to continue if yes Press 1\n\n\t if no Press 0\t");
scanf("%d",&YN);
}
while(YN==1);
return(0);
}
void FIFO(char s[],char F[],int l,int f)
{
int i,j=0,k,flag=0,cnt=0;
printf("\n\t PAGE\t FRAMES \t FAULTS");
for(i=0;i<l;i++)
{
for(k=0;k<f;k++)
{
if(F[k]==s[i])
flag=1;
}
if(flag==0)
{
printf("\n\t%c\t",s[i]);
F[j]=s[i];
j++;
for(k=0;k<f;k++)
{
printf("%c",F[k]);
}
printf("\t page fault %d",cnt);
cnt++;
}
else
{
flag=0;
printf("\n\t%c\t",s[i]);
for(k=0;k<f;k++)
{
printf("%c",F[k]);
}
printf("\t no page fault");
}
if(j==f)
j=0;
}
}
void LRU(char s[],char F[],int l,int f)
{
int i,j=0,k,m,flag=0,cnt=0,top=0;
printf("\n\t PAGE \t FRAMES \t FAULTS");
for(i=0;i<l;i++)
{
for(k=0;k<f;k++)
{
if(F[k]==s[i])
{
flag=1;
break;
}
}
printf("\n\t%c\t",s[i]);
if(j!=f && flag!=1)
{
F[top]=s[i];
j++;
if(j!=f)
top++;
}
else
{
if(flag!=1)
{
for(k=0;k<top;k++)
{
F[k]=F[k+1];
}
F[top]=s[i];
}
if(flag==1)
{
for(m=k;m<top;m++)
{
F[m]=F[m+1];
}
if(j!=f)
{
F[top-1]=s[i];
}
else
F[top]=s[i];
}
}
for(k=0;k<f;k++)
{
printf("%c",F[k]);
}
if(flag==0)
{
printf("\t page fault %d",cnt);
cnt++;
}
else
printf("\t no page fault");
flag=0;
}
}
