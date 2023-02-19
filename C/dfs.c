#include<stdio.h>

int stack[15],top=-1,vertex[15],visited[15],adjmatrix[15][15],vcount;

void push(int n){

        stack[++top]=n;
    }



int isstackempty(){

    if(top==-1){

        return 1;
    }

    return 0;
}


int pop(){

    return stack[top--];

}


int adjvertex(int n){

    for(int i=1;i<=vcount;++i){

        if(adjmatrix[n][i]!=0 && visited[i]==0)

            return i;
    }

    return 0;
}


void dfs(int s){

    int popelemnt,v;

   

    push(vertex[s]);

    printf("dfs   :");

    while(!isstackempty()){

        popelemnt=pop();
        if( visited[popelemnt]==0){
            visited[popelemnt]=1;
            printf("%d -> ",vertex[popelemnt]);

        }

        for(int i=0;i<vcount;++i){

            if(v=adjvertex(popelemnt)){
                // printf("v==%d",v);
                push(v);
            }

        }

    }
}


int vertex_pos(int n){
    for(int i=0;i<vcount;++i){
        if(vertex[i]==n)
            return i;
    }
}

void main(){

    int i,n,j,edge,strt,end;

    printf("Enter the number of vertex:");

    scanf("%d",&vcount);
    printf("Enter the  vertices:");
    for(i=1;i<=vcount;++i)
    {
        printf("vertex %d:",i);
        scanf("%d",&n);
        vertex[i]=n;

        visited[i]=0;
    }
    // printf("Enter adjacency matrix:\n");
    // for(i=1;i<=vcount;++i){
    //     for(j=1;j<=vcount;++j){
    //         scanf("%d",&adjmatrix[i][j]);
    //     }
    // }
    for(i=1;i<=vcount;++i){

        for(j=1;j<=vcount;++j){

            adjmatrix[i][j]=0;
        }
    }

    printf("Enter number od edges:");

    scanf("%d",&edge);

    for(i=1;i<=edge;++i){

        printf("Starting vertex of edge-%d:",i);
        scanf("%d",&strt);

        printf("Ending vertex of edge-%d:",i);
        scanf("%d",&end);

        adjmatrix[vertex_pos(strt)][vertex_pos(end)]=1;
        // adjmatrix[end][strt]=1;

    }
    printf("Enter the traversal starting vertex:");
    scanf("%d",&n);
    dfs(vertex_pos(n));
    
}