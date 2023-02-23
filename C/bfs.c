#include<stdio.h>

void main()
{
    int queue[10],f=-1,r=-1;
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
    
    queue[++r] = s;
    ++f;
    visited[s] = 1;
    
    while(r>=f)
    {
        s = queue[f++];
        printf("%d",s);
        
        for(i=1;i<=n;i++)
        {
            if(cost[s][i]==1 && visited[i]==0)
            {
                queue[++r] = i;
                visited[i] = 1;
            }
        }
    }
}
