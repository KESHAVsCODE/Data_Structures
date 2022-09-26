#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *stack=NULL;
struct node* createnode(int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->info=value;
    return temp;
}
void push(int data)
{
    struct node *temp;
    temp=createnode(data);
    if(stack==NULL){
        stack=temp;
    }
    else
    {
        temp->next=stack;
        stack=temp;
    }
}
void pop()
{
    struct node *t;
    if(stack==NULL)
        printf("list is empty");
    else{
        t=stack;
        printf("\n poped value is %d",t->info);
        stack=stack->next;
        free(t);
    }
}
void peek()
{
    if(stack==NULL)
        printf("\n list is empty:");
    else{
        printf("\n peek element is %d",stack->info);
    }
}
void viewstack()
{
    struct node *t;
    t=stack;
    if(stack==NULL)
        printf("LIST IS EMPTY:");
    else
    {
        while(t!=NULL)
        {
            printf("\n%d",t->info);
            t=t->next;
        }
    }
}
void main()
{
    int choice,data;
    while(1){
        system("cls");
        printf("\n 1.push data:");
        printf("\n 2.pop data:");
        printf("\n 3.peek data:");
        printf("\n 4.view stack:");
        printf("\n 0.exit");
        printf("\n enter choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter value");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            viewstack();
            break;
        case 0:
            exit(0);
        default:
            printf("\nINVALID CHOICE:");
            break;
        }
        getch();
    }

}

