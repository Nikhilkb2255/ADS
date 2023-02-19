#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *l,*r;
}*root=NULL,*newnode;

void insert(int n){
    newnode=(struct node*)malloc(sizeof(struct node));
    struct node *r,*p;
    newnode->data=n;
    newnode->l=newnode->r=NULL;
    if(root==NULL)root=newnode;
    else{
        r=root;
        while(r!=NULL){
            if(n<r->data){
                p=r;
                r=r->l;
            }
            else{
                p=r;
                r=r->r;
            }
        }
        if(n<p->data)
            p->l=newnode;
        else
            p->r=newnode;
    }

}

struct node* delete(struct node *p,int n){
    struct node *t;
    if(p==NULL)return p;
    if(n<p->data){
        p->l=delete(p->l,n);
    }
    else if(n>p->data){
        p->r=delete(p->r,n);
    }
    else{
        if(p->l==NULL){
            t=p->r;
            free(p);
            return t;
        }
        else if(p->r==NULL){
            t=p->l;
            free(p);
            return t;
        }
        
            t=p->r;
            while(t && t->l != NULL ){
                t=t->l;
            }
            p->data=t->data;
            p->r=delete(p->r,t->data);
        }
        return p;
    }
    

struct node* search(int n){
    struct node *r=root,*p;
    if(root->data==n){
        return root;
    }
    while(r!=NULL){
        if(n<r->data){
                p=r;
                r=r->l;
        }
        else if(n>r->data){
            p=r;
            r=r->r;
        }
        else{
            return r;
        }
    }
    return NULL;
    

}


void inorder(struct node *r){
    if(r==NULL)return;
    inorder(r->l);
    printf("%d\t",r->data);
    inorder(r->r); 

}


void preorder(struct node *r){
    if(r==NULL)return;
    printf("%d\t",r->data);
    preorder(r->l);
    preorder(r->r);
    
}


void postorder(struct node *r){
    if(r==NULL)return;
    postorder(r->l);
    postorder(r->r);
    printf("%d\t",r->data);
}


void main(){
    int c,n;
    struct node *s;
    while(1){
    printf("\n\nMENU\n----\n\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit\n\n\t\tEnter choice:");
        scanf("%d",&c);
        switch(c){
            case 1:printf("\n\tEnter number to be inserted:");
                    scanf("%d",&n);
                    insert(n);
                    break;
            case 2:printf("\n\tEnter number to be deleted:");
                    scanf("%d",&n);
                    if(search(n))
                        delete(root,n);
                    else{
                        printf("\ndata not found!deletion cannot perform");
                    }
                    break;
            case 3:printf("\nElements:");
                    inorder(root);
                    printf("\nElements (preorder):");
                    preorder(root);
                    printf("\nElements (postorder):");
                    postorder(root);
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid");
        }
    }
}