#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *delete_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);
void main()
{
int choice;
do{
printf("\n1.Create list\n2.Display\n3.Insert at beginning\n4.Insert at the end\n5.Insert
before a node\n6.Insert after a node\n7.Delete at beginning\n8.Delete at end\n9.Delete a node\
n10.Delete after a node\n11.Delete entire list\n12.Sort the list\n13.Exit\n\n");
printf("Enter your choice : ");
scanf(" %d",&choice);
switch(choice)
{
case 1 :
start = create_ll(start);
printf("\nLinked list created\n");
break;
case 2 :
start = display(start);
break;
case 3 :
start = insert_beg(start);break;
case 4 :
start = insert_end(start);
break;
case 5 :
start = insert_before(start);
break;
case 6 :
start = insert_after(start);
break;
case 7 :
start = delete_beg(start);
break;
case 8 :
start = delete_end(start);
break;
case 9 :
start = delete_node(start);
break;
case 10 :
start = delete_after(start);
break;
case 11:
start = delete_list(start);
break;
case 12:
start = sort_list(start);
break;
default:
printf("Wrong choice");
}
}while(choice!=13);
}
struct node *create_ll(struct node *start)
{
struct node *newnode,*ptr;
int num;
printf("\nEnter -1 to end creation.\nEnter data : ");
scanf(" %d",&num);
while(num!=-1)
{
newnode = (struct node*)malloc(sizeof(struct node));
newnode -> data = num;
if(start==NULL)
{
newnode -> next = NULL;
start=newnode;
}
else
{
ptr=start;while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next = newnode;
newnode->next = NULL;
}
printf("\nEnter data : ");
scanf("%d",&num);
}
return start;
}
struct node *display(struct node *start)
{
struct node *ptr;
ptr=start;
while(ptr!=NULL)
{
printf("%d\t",ptr->data);
ptr=ptr->next;
}
return start;
}
struct node *insert_beg(struct node *start)
{
struct node *newnode;
int num;
printf("\nEnter data : ");
scanf(" %d",&num);
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = num;
newnode->next = start;
start = newnode;
}
struct node *insert_end(struct node *start)
{
struct node *ptr, *new_node;
int num;
printf("\n Enter the data : ");
scanf("%d",&num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = num;
new_node->next = NULL;
ptr = start;
while(ptr->next!=NULL)
ptr = ptr->next;
ptr->next = new_node;
return start;
}
struct node *insert_after(struct node *start){
struct node *newnode,*ptr,*preptr;
int num,val;
printf("Enter data to be inserted : ");
scanf(" %d",&num);
printf("Enter value after which %d is to be inserted : ",num);
scanf(" %d",&val);
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = num;
ptr=start;preptr=ptr;
while(preptr -> data != val)
{
preptr=ptr;
ptr = ptr->next;
}
preptr -> next = newnode;
newnode -> next =ptr;
return start;
}
struct node *insert_before(struct node * start)
{
struct node *newnode,*ptr,*preptr;
int num,val;
printf("Enter data to be inserted : ");
scanf(" %d",&num);
printf("Enter value before which %d is to be inserted : ",num);
scanf(" %d",&val);
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = num;
ptr=start;preptr=ptr;
while(ptr -> data != val)
{
preptr=ptr;
ptr = ptr->next;
}
preptr -> next = newnode;
newnode -> next =ptr;
return start;
}
struct node *delete_node(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value of the node which has to be deleted : ");
scanf("%d", &val);
ptr = start;
if(ptr->data==val)
{
start = delete_beg(start);
return start;}
else
{
while(ptr->data!=val)
{
preptr = ptr;
ptr = ptr->next;
}
preptr->next = ptr->next;
free(ptr);
return start;
}
}
struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr=start;
start = start->next;
free(ptr);
return start;
}
struct node *delete_end(struct node *start)
{
struct node *ptr,*preptr;
ptr=start;
while(ptr -> next != NULL)
{
preptr = ptr;
ptr = ptr->next;
}
preptr->next = NULL;
free(ptr);
return start;
}
struct node *delete_after(struct node *start)
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the value after which the node has to be deleted : ");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(preptr->data!=val)
{
preptr = ptr;
ptr = ptr->next;
}
preptr->next = ptr->next;
free(ptr);return start;
}
struct node *delete_list(struct node *start)
{
struct node *ptr;
if(start!=NULL)
{
ptr = start;
while(ptr!=NULL)
{
printf("\n %d is to be deleted next", ptr->data);
start = delete_beg(ptr);
ptr = start;
}
}
return start;
}
struct node *sort_list(struct node *start)
{
struct node *ptr1, *ptr2;
int temp;
ptr1 = start;
while(ptr1->next!=NULL)
{
ptr2 = ptr1->next;
while(ptr2!=NULL)
{
if(ptr1->data > ptr2->data)
{
temp = ptr1->data;
ptr1->data = ptr2->data;
ptr2->data = temp;
}
ptr2 = ptr2->next;
}
ptr1 = ptr1->next;
}
return start;
}
