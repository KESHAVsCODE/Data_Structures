#include<stdio.h>
#include<conio.h>
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack* createstack(int cap)
{
    struct ArrayStack *stack;
    stack=malloc(sizeof(struct ArrayStack));
    stack->top=-1;
    stack->capacity=cap;
    stack->array=malloc(sizeof(int)*cap);
    return stack;
}
int isfull(struct ArrayStack *stack)
{
    if(stack->top==stack->capacity-1)
        return 1;
    else
        return 0;
}
int isempty(struct ArrayStack *stack)
{
    if(stack->top==-1)
        return 1;
    else
        return 0;
}
void push(struct ArrayStack *stack,int item)
{
        stack->top++;
        stack->array[stack->top]=item;
}
int pop(struct ArrayStack *stack)
{
    int item;
        item=stack->array[stack->top];
        stack->top--;
        return item;
}
void main()
{
    int choice,item;
    struct ArrayStack *stack;
    stack=createstack(4);
    while(1){
    system("cls");
    printf("\n1.push element ");
    printf("\n2.pop element ");
    printf("\n3.exit ");
    printf("\nEnter your choice");
    scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(!isfull(stack)){
              printf("\nEnter a element");
              scanf("%d",&item);
              push(stack,item);
              printf("\nelement inserted");
            }
            else
              printf("\nstack is overflow you can not insert any element element");
            break;
        case 2:
            if(!isempty(stack)){
                item=pop(stack);
                printf("\npoped element is %d",item);
            }
            else
                printf("stack is empty");
            break;
        case 3:
            exit(0);
    }
    getch();
   }
}
