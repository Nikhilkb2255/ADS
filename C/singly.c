#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insertbegin();
void insertend();
void insertrandom();
void deletebegin();
void deleteend();
void deleterandom();
void search();
void display();
void main()
{
    int choice = 0;
    while(choice !=9)
    {
        printf("\n\nMAIN MENU");
        printf("\n---------");
        printf("\nChoose an option");
        printf("\n1.Insert at begining");
        printf("\n2.Insert at end");
        printf("\n3.Insert at random");
        printf("\n4.Delete at begining");
        printf("\n5.Delte at end");
        printf("\n6.Delete at random");
        printf("\n7.Dispaly");
        printf("\n8.Search");
        printf("\n9.Exit");
        
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertbegin();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertrandom();
                break;
            case 4:
                deletebegin();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                deleterandom();
                break;
            case 7:
                display();
                break;
            case 8:
                search();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\nPLz enter a valid choice!!!");
        }
    }
}

void insertbegin()
{
    int item;
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("Enter th value : ");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted !");
    }
}

void insertend()
{
    int item;
    struct node *ptr,*temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter th value : ");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = NULL;
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        printf("\nNode inserted !");
    }
}

void insertrandom()
{
    int item,loc,i;
    struct node *ptr,*temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the value : ");
        scanf("%d",&item);
        ptr->data = item;
        printf("Enter the location : ");
        scanf("%d",&loc);
        
        temp = head;
        for(i=1;i<loc-1;i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted !");
    }
}
    
void deletebegin()
{
    struct node *ptr;
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted !");
    }
}

void deleteend()
{
    struct node *ptr,*ptr1;
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nNode deleted !");
    }
}

void deleterandom()
{
    int loc,i;
    struct node *ptr,*ptr1;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the location : ");
        scanf("%d",&loc);
        ptr = head;
        for(i=1;i<loc;i++)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = ptr->next;
        free(ptr);
        printf("\nNode deleted !");
    }
}

void display()
{
    struct node *ptr;
    if(ptr==NULL)
    {
        printf("\nEmpty !");
    }
    else
    {
        ptr = head;
        printf("\nValues are ...\n");
        while(ptr != NULL)
        {
            printf("\t%d",ptr->data);
            ptr = ptr->next;
        }
    }
}

void search()
{
    int s,i=0,flag;
    struct node *ptr;
    ptr = head;
    
    if(ptr==NULL)
    {
        printf("\nEmpty !");
    }
    else
    {
        printf("\nEnter the item to search : ");
        scanf("%d",&s);
        while(ptr!=NULL)
        {
            if(ptr->data == s)
            {
                printf("\nItem found at postion %d",i+1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if(flag == 1)
        {
            printf("\nItem not found !");
        }
    }
}



