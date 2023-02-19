#include<stdio.h>
void main(){
    int row,col,v1,v2,mincost,count,sum=0,visited[20],vertex[20],vcount,costmatrix[20][20];
    printf("Enter the no of vertex:");
    scanf("%d",&vcount);
    printf("Enter %d verteces:",vcount);
    for(row=0;row<vcount;++row){
        printf("\nvertex %d:",row+1);
        scanf("%d",&vertex[row]);
        visited[row]=0;
    }
    printf("Enter cost matrix:");
    for(row=0;row<vcount;++row){
        for(col=0;col<vcount;++col){
            scanf("%d",&costmatrix[row][col]);
            if(costmatrix[row][col]==0)
                costmatrix[row][col]=999;
        }
    }
    printf("\nMinimum cost spanning tree:\n");
    visited[0]=1;
    count=1;
    while(count<vcount){
        for(row=0,mincost=999;row<vcount;++row){
        for(col=0;col<vcount;++col){
            if(costmatrix[row][col]<mincost){
                if(visited[row]!=0){
                    mincost=costmatrix[row][col];
                    v1=row;
                    v2=col;
                    // printf("\nr=%d  c=%d",row,col);
                }
            }
            
        }
    
    }
    if( visited[v2]==0){
        // printf("\nif r=%d  c=%d",v1,v1);
        printf("\nEdge %d:%d -> %d  cost=%d",count,vertex[v1],vertex[v2],mincost);
        ++count;
         visited[v2]=1;
         sum+=mincost;
         
    }
    costmatrix[v1][v2]=costmatrix[v2][v1]=999;

}
printf("\nSum=%d",sum);


}