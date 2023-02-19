#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
} *root = NULL, *newnode;
void createnode(int);
void insert_data();
void display(struct node *);
void main()
{
    int choice;
    printf("**MENU**\n\t1.INSERT\n\t2.DELETE\n\t3.DISPLAY\n\t4.EXIT");
    while (1)
    {
        printf("\nEnter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_data();
            break;
        case 2:
            break;
        case 3:
            display(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Operation!");
        }
    }
}

void createnode(int data)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = newnode->left = NULL;
}
void insert_data()
{
    int d;
    struct node *t, *pre;
    printf("Enter the data");
    scanf("%d", &d);
    createnode(d);
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        t = root;
        while (t != NULL)
        {
            if (d <= t->data)
            {
                pre = t;
                t = t->left;
            }
            else if (d > t->data)
            {
                pre = t;
                t = t->right;
            }
        }
        if (d <= pre->data)
        {
            pre->left = newnode;
        }
        else
        {
            pre->right = newnode;
        }
    }
}
void display(struct node *r)
{
    if (r != NULL)
    {
        display(r->left);
        printf("%d  ", r->data);

        display(r->right);
    }
}