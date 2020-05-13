#include <stdio.h>
#include<string.h>
#define MAX 30
int top = -1;
int stk[MAX];
void push(char);
char pop();
void main()
{
char exp[MAX];
char temp;
int i, flag = 1;
printf("Enter an algebraic exp :");
gets(exp);
for(i=0;i<strlen(exp);i++)
{
if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
push(exp[i]);
if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
if(top == -1)
flag = 0;
else
{
temp = pop();
if(exp[i] == ')' && (temp == '{' || temp == '['))
flag = 0;
if(exp[i] == '}' && (temp == '(' || temp == '['))
flag = 0;
if(exp[i] == ']' && (temp == '{' || temp == '('))
flag = 0;
}
}
if(top >= 0)
flag = 0;
if(flag == 1)printf("\n Valid exp");
else
printf("\n Invalid exp");
}
void push(char item)
{
if(top == MAX-1)
{
printf("\nStack is Full!!!");
}
else
{
top++;
stk[top] = item;
}
}
char pop()
{
if(top == -1)
printf("\nno value to pop");
else
return(stk[top-1]);
}
