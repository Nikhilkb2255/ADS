#include<stdio.h>
#include<stdlib.h>

int n, i, j, s;
int mind, minn, count;
int cost[10][10], dis[10], vis[10], pre[10];

void main()
{    
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    printf("Enter cost matrix :\n");
    for(i=0;i<n;++i)
	{
        for(j=0;j<n;++j)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
	        cost[i][j]=999;
        }
    }
    printf("Enter the start:");
    scanf("%d",&s);
    for(i=0;i<n;i++){
        dis[i]=cost[s][i];
        pre[i]=s;
        vis[i]=0;
    }
    dis[s]=0;
    vis[s]=1;
    for(count=1;count<n;count++)
    {
        for(i=0,mind=999;i<n;i++)
        {
            if(dis[i]<mind && !vis[i])
            {
                mind=dis[i];
                minn=i;
            }
        }
        vis[minn]=1;
        for(i=0;i<n;i++){
            if(!vis[i] &&  mind+cost[minn][i]<dis[i])
            {
                dis[i]=mind+cost[minn][i];
                pre[i]=minn;
            }
        }
        
    }
    for(i=0;i<n;++i)
    if(i!=s)
    {
        printf("\ndistance(%d)::%d",i,dis[i]);
        printf("\npath:%d",i);
        j=i;
    
        while(j!=s)
        {
            j=pre[j];
            printf("<- %d",j);
        }
    }
}
