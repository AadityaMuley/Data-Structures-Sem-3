#include<stdio.h>
#include<stdlib.h>
#define MAX 4
void main()
{
int ch,i,j;
int adj[MAX][MAX];
int visited[MAX]={0};
int visit[MAX]={0};
printf("Create a matrix :\n");
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
scanf("%d",&adj[i][j]);
}
}
do
{
printf("\n1.BFS\n2.DFS\n3.EXIT\n");
printf("Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1 : BFS(adj,visited,0);
break;
case 2 : DFS(adj,visit,0);
break;
case 3 : exit(0);
}
}while(ch!=3);
}void BFS(int adj[][MAX],int visited[],int start)
{
int queue[MAX],rear = -1,front=-1,i;
queue[++rear] = start;
visited[start] = 1;
while(rear!=front)
{
start = queue[++front];
printf("%c\t",start+65);
for(i=0;i<MAX;i++)
{
if(adj[start][i]==1 && visited[i]==0)
{
queue[++rear] = i;
visited[i] = 1;
}
}
}
}
void DFS(int adj[][MAX],int visit[],int start)
{
int stack[MAX],top = -1,i;
stack[++top] = start;
printf("%c\t",start+65);
visit[start]=1;
while(top!=-1)
{
start = stack[top];
for(i=0;i<MAX;i++)
{
if(adj[start][i]==1 && visit[i]==0)
{
stack[++top] = i;
printf("%c\t",i+65);
visit[i] = 1;
break;
}
}if(i==MAX)
top--;
}
}
