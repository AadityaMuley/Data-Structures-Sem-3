#include<stdio.h>
void qsort(int arr[],int low,int high);
int partition(int arr[],int low,int high);
void main()
{
int arr[20],i,size;
printf("Enter number of elements : ");
scanf(" %d",&size);
printf("Enter %d elements : \n",size);
for(i=0;i<size;i++)
scanf(" %d",&arr[i]);
qsort(arr,0,size-1);
printf("Sorted elements : \n");
for(i=0;i<size;i++)
printf("%d\t",arr[i]);
printf("\n");
}
void qsort(int arr[],int low,int high)
{
int pivot;
if(low<high)
{
pivot = partition(arr,low,high);
qsort(arr,low,pivot-1);
qsort(arr,pivot+1,high);
}
}
int partition (int arr[],int low,int high)
{
int j,temp;int pivot = arr[high];
int i = (low - 1);
for(j=low;j<=(high-1);j++)
{
if(arr[j]<=pivot)
{
i++;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
temp=arr[i+1];
arr[i+1]=arr[high];
arr[high]=temp;
return(i+1);
}
