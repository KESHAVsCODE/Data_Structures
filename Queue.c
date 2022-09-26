#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue
{
    int capacity;
    int front;
    int rear;
    int *qarr;
};
void viewqueue(struct queue *que);
struct queue* createqueue(int capacity);
int isfullque(struct queue *que);
int isemptyque(struct queue *que);
int queuecapacity(struct queue *que);
void insertque(struct queue *que,int value);
void deletion(struct queue *que);
void halfque(struct queue *que);
struct queue* DoubleQue(struct queue *que);s
struct queue* createqueue(int capacity)
{
    struct queue *que;
    que=(struct queue*)malloc(sizeof(struct queue));
    que->capacity=capacity;
    que->front=-1;
    que->rear=-1;
    que->qarr=(int*)malloc(sizeof(int)*que->capacity);
    return que;
}
int isfullque(struct queue *que)
{
    if(que->front==0&&que->rear==que->capacity-1)
        return 1;
    else if(que->front==que->rear+1)
        return 1;
    else
        return 0;
}
int isemptyque(struct queue *que)
{
    if(que->rear==-1)
        return 1;
    else
        return 0;
}
int queuecapacity(struct queue *que)
{
    return que->capacity;
}
void insertque(struct queue *que,int value)
{
        if(isemptyque(que)){
            que->front=0;
            que->rear=0;
        }
        else if(isfullque(que)){
            que=DoubleQue(que);                         //here we can apply change
            ++(que->rear);
        }
        else{
            if(que->rear==que->capacity-1)
                que->rear=0;
            else{
                ++que->rear;
            }
        }
        que->qarr[que->rear]=value;
}
void deletion(struct queue *que)
{
    int size=1;
    if(isemptyque(que))
        printf("\n queue is empty");
    else if(que->front==que->rear){
        que->front=-1;
        que->rear=-1;
    }
    else if(que->front==que->capacity-1){
        que->front=0;
    }
    else{
        que->front++;
    }
    if(que->front>-1){
        for(int i=que->front;i!=que->rear;){
                size++;
            if(i==que->capacity-1)
                i=0;
            else
                i++;
        }
        if(size==que->capacity/2){
            halfque(que);
        }
    }
}
void halfque(struct queue *que)
{
    int *temp,i,j;
    temp=(int*)malloc(sizeof(int)*que->capacity/2);
    for(i=que->front,j=0;j<=que->capacity/2-1;j++)
    {
        temp[j]=que->qarr[i];
        if(i==que->capacity-1)
            i=0;
        else
            i++;
    }
    free(que->qarr);
    que->qarr=temp;

    que->front=0;
    que->rear=que->capacity/2-1;
}
struct queue* DoubleQue(struct queue *que)
{
    int i,j,*temp;
    que->capacity=que->capacity*2;
    temp=(int*)malloc(que->capacity*4);
    for(i=que->front,j=0;i!=que->rear;j++)
    {
        temp[j]=que->qarr[i];
        if(i==que->capacity/2-1&&i!=que->rear)
            i=0;
        else
            i++;
    }
    free(que->qarr);
    que->qarr=temp;
    que->front=0;
    que->rear=que->capacity/2-1;
    return temp;
}
struct queue* deleteque(struct queue *que)
{
    free(que->qarr);
    free(que);
    return NULL;
}
void viewqueue(struct queue *que)
{
    int i;
    if(isemptyque(que))
        printf("\n queue is empty");
    else
    {
        for( i=que->front;i!=que->rear;){
                printf("\n%d",que->qarr[i]);
            if(i==que->capacity-1)
                i=0;
            else
                i++;
        }
        printf("\n%d",que->qarr[i]);
    }
}
int main()
{
    int cap,choice,value,d;
    struct queue *you;
    printf("\nEnter capacity of queue:");
    scanf("%d",&cap);
    while(1)
    {
        system("cls");
        if(cap<1){
            printf("\nplease enter at least 1 capacity\n");
            printf("\nEnter capacity of queue:");
            scanf("%d",&cap);
        }
        else
            break;
    }
    you=createqueue(cap);
    while(1){
        system("cls");
        printf("\n 1. insertion:");
        printf("\n 2. deletion:");
        printf("\n 3. viewcapacity");
        printf("\n 4. delete queue:");
        printf("\n 5. view queue");
        printf("\n 0.exit");
        printf("\n enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n enter value:");
            scanf("%d",&value);
            insertque(you,value);
            break;
        case 2:
            deletion(you);
            break;
        case 3:
            printf(" queue capacity is %d",queuecapacity(you));
            printf("\n FRONT = %d",you->front);
            printf("\n REAR = %d",you->rear);
            break;
        case 4:
            deleteque(you);
            printf("\n queue is deleted");
            break;
        case 5:
            viewqueue(you);
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


