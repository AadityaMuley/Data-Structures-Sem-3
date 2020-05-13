#include<stdio.h>
#include<stdlib.h>
# define MAX 10
void main()
{
int array[MAX],num,first,last,mid,i,j,flag=0;
printf("Enter elements in array : ");
for(i=0;i<MAX;i++)
scanf(" %d",&array[i]);
for(i=0;i<MAX;i++)
{
for(j=i+1;j<MAX;j++)
{
if (array[i] > array[j])
{
int temp;
temp=array[i];
array[i]=array[j];
array[j]=temp;
}
}
}
printf("Sorted array is : \n");
for(i=0;i<MAX;i++)
printf("%d ",array[i]);
printf("\n");
first=0;last=MAX-1;
printf("Enter the number to be searched : ");
scanf("%d",&num);
while(!flag && first<=last)
{
mid=(first+last)/2;
if(array[mid]==num)
{
printf("Element %d is present at position %d\n",num,mid+1);
flag=1;
}
else if(array[mid]>num)
last=mid-1;
else
first=mid+1;
}
if(first>last && flag==0)
printf("elemnt %d does not exist in array \n",num);
}
