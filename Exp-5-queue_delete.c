#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;
void insert();
int delete();
int peek();
void display();
void main()
{
int option, val;
do
{
printf("\nMain Menu");
printf("\n1. Insert");
printf("\n2. Delete");
printf("\n3. Peek");
printf("\n4. Dispaly");
printf("\n5. Exit");
printf("\n\nEnter your choice");
scanf("%d", &option);
switch(option)
{
case 1:
insert();
break;
case 2:
val = delete();
if(val!=-1)
printf("\nThe number deleted is :%d", val);
break;
case 3:
val = peek();
if(val!=-1)
printf("\nThe first value in queue is : %d",val);
break;
case 4:
display();
break;
}
}while(option != 5);
}void insert()
{
int num;
printf("\nEnter the number to be inserted in the queue :");
scanf("%d", &num);
if(front == 0 && rear == MAX-1)
printf("\n OVERFLOW");
else if(front == -1 && rear == -1)
{
front = rear = 0;
queue[rear] = num;
}
else
{
rear++;
queue[rear] = num;
}
}
int delete()
{
int val;
if(front == -1 && rear == -1)
{
printf("\n UNDERFLOW");
return -1;
}
val = queue[front];
if(front == rear)
front = rear = -1;
else
{
if(front == MAX-1)
front = 0;
else
front ++;
}
return val;
}
int peek(){
if(front == -1 && rear == -1)
{
printf("\nQueue is empty");
return -1;
}
else
return queue[front];
}
void display()
{
printf("\n");
if(front == -1 && rear == -1)
printf("\n Queue is empty");
else
{
if(front<rear)
{
for(int i=0;i<=rear;i++)
{
printf("\t %d", queue[i]);
}
}
else
{
for(int i=0;i<MAX;i++)
{
printf("\t %d", queue[i]);
}
for(int i=0;i<=rear;i++)
{
printf("\t %d", queue[i]);
}
}
}
}
