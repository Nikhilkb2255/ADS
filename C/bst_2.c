#include<stdio.h>
#include<stdlib.h>
 
int n, i, j, u, v, f=1;
int cost[10][10], visited[10]={0}, mincost=0, min;
 
void main()
{
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
 
	printf("\nEnter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
            cost[i][j]=999;
    }
 
	visited[1]=1;
    printf("\n");
 
	while(f < n)
    {
        for(i=1,min=999;i<=n;i++)
        for(j=1;j<=n;j++)
 
		if(cost[i][j]< min)
        if(visited[i]!=0)
        {
            min=cost[i][j];
            u=i;
            v=j;
        }
 
		if(visited[u]==0 || visited[v]==0)
        {
            printf("\n Edge %d:(%d %d) cost:%d",f++,u,v,min);
            mincost+=min;
            visited[v]=1;
        }
 
		cost[u][v]=cost[v][u]=999;
 
	}
 
	printf("\n Minimun cost=%d",mincost);
 
}
