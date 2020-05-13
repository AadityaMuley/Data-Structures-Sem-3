#include <stdio.h>
#define MAX 10
int QUEUE[MAX],front=-1,rear=-1;
/** function
: insert(),
to push an item into queue.
**/
void insert(int queue[],int ele)
{
if(rear==-1)
{
front=rear=0;
queue[rear]=ele;
}
else if(rear==MAX-1)
{
printf("\nQUEUE is full.\n");
return;
}
else
{
rear++;
queue[rear]=ele;
}
printf("\nItem inserted..");
}
void display_Q(int queue[])
{
int i;
if(rear==-1) { printf("\nQUEUE is Empty.\n"); return; }
for(i=front;i<=rear;i++)
{ printf("%d\n",queue[i]); }}
void dequeue(int queue[])
{
int ele;
if(front==-1)
{
printf("QUEUE is Empty.\n");
return;
}
else if(front==rear)
{
ele=queue[front];
front=rear=-1;
}
else
{
ele=queue[front];
front++;
}
printf("\nItem dequeued : %d.",ele);
}
int main()
{
int ele,choice;
while(1)
{
//clrscr();
printf("\nQUEUE Elements are :\n");
display_Q(QUEUE);
printf("------------------------------------------------\nEnter choice \n1:Insert\
n2:Display\n3:Dequeue\n0:Exit\n");
scanf("%d",&choice);switch(choice)
{
case 0:
exit(1);
break;
case 1:
printf("Enter an element to insert:\n");
scanf("%d",&ele);
insert(QUEUE,ele);
break;
case 2:
display_Q(QUEUE);
break;
case 3:
dequeue(QUEUE);
break;
default:
printf("\nInvalid choice\n");
break;
}
} //end of while(1)
return 0;
}
