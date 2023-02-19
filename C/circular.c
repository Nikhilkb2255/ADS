#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void display();
void main(){
    int c;
    printf("\n**MENU**\n\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.DISPLAY\n\t4.QUIT");
    while(1){
        printf("\nEnter choice:");
        scanf("%d",&c);
        switch(c){
            case 1:enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
        default:printf("Invalid Input");
        }
    }

}
void enqueue(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d",&newnode->data);
    
    if(front==NULL)
    {
	newnode->next=newnode;
        front=rear=newnode;
	front->next=front;

	
    }
    else{
	newnode->next=front;
        rear->next=newnode;
        rear=newnode;
	
    }
}
void dequeue(){
    struct node *t,*curr;
    if(front==NULL){
        printf("\nUnderflow!");
    }
    else{
        t=front;
        printf("%d deleted",t->data);
	if(front->next==front)
		front=NULL;
        else{
		for(curr=front;curr->next!=front;curr=curr->next);
		
		front=front->next;
		curr->next=front;
        	free(t);
	}
    }
}
void display(){
    struct node *cur;
    if(front==NULL)
        printf("\nNo elements");
    else{
	printf("\nElements:");
        for(cur=front;cur->next!=front;cur=cur->next)
            printf("%d\t",cur->data);
	printf("%d\t",cur->data);
    }
    
}