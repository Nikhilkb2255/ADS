#include<stdio.h>

void main()
{
    int stack[10],top=-1;
    int n,i,j,s;
    int cost[10][10],visited[10]={0};
    
    printf("\nEnter the num of nodes : ");
    scanf("%d",&n);
    printf("\nEnter adj matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    
    printf("Enter starting vertex : ");
    scanf("%d",&s);
    
    stack[++top] = s;
    visited[s] = 1;
    
    while(top!=-1)
    {
        s = stack[top--];
        printf("\t%d",s);
        
        for(i=1;i<=n;i++)
        {
            if(cost[s][i]==1 && !visited[i])
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}
