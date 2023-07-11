%{
#include<stdio.h>
#include<string.h>
int i=0,o=0,k,flag=0;
char id[10][10], op[10][10];
%}
%%
[a-zA-Z0-9]+ {flag++;strcpy(id[i],yytext);i++;}
[+*] {flag--;strcpy(op[o],yytext);o++;}
.|\n {return 0;}
%%
int main()
{
printf(“enter the expression: \n”);
yylex();
if(flag!=1)
{
printf(“\n Invalid expression: \n”);
}
else
{
printf(“\n Valid expression \n”);
printf(“\n Operators are: \n”);
for(k=0;k<o;k++)
{
printf(“%s\t”,op[k]);
}
printf(“\n Identifiers are: \n”);
for(k=0;k<i;k++)
{
printf(“%s\t”,id[k]);
}
}
}
int yywrap()
{
return 1;
}
