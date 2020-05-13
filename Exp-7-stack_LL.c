#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
struct stack
{
int data;
struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
int peek(struct stack *);
void main()
{
int val,choice;
do
{
printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
printf("\nEnter your choice : ");
scanf(" %d",&choice);
switch(choice)
{case 1 : printf("Enter element to be added : ");
scanf("%d",&val);
top=push(top,val);
break;
case 2 : top=pop(top);
break;
case 3 : val=peek(top);
if(val!=-1)
printf("Top of stack is %d\n",val);
else
printf("Stack is empty\n");
break;
case 4 : top=display(top);
break;
}
}while(choice != 5);
}
struct stack *push(struct stack *top,int val)
{
struct stack *ptr;
ptr=(struct stack*)malloc(sizeof(struct stack));
ptr->data=val;
if(top==NULL)
{
ptr->next=NULL;
top=ptr;
}
else
{
ptr->next=top;
top=ptr;}
return top;
}
struct stack *pop(struct stack *top)
{
struct stack *ptr;
ptr=top;
if(ptr==NULL)
printf("\nstack underflow\n");
else
{
top=top->next;
printf("Deleted value is %d\n",ptr->data);
free(ptr);
}
return top;
}
int peek(struct stack *top)
{
if(top==NULL)
return -1;
else
return top->data;
}
struct stack *display(struct stack *top)
{
struct stack *ptr;
ptr=top;
if(top==NULL)printf("\nStack is empty\n");
else
{
while(ptr != NULL)
{
printf("%d\t",ptr->data);
ptr=ptr->next;
}
}
return top;
}
