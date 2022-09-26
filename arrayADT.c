#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct arrayadt
{
    int capacity;
    int lastindex;
    int *ptr;
};
struct arrayadt* createarray(int cap)
{
    struct arrayadt *A1;
    A1=(struct arrayadt*)malloc(sizeof(struct arrayadt));
    A1->capacity=cap;
    A1->lastindex=-1;
    A1->ptr=calloc(A1->capacity,sizeof(int));
    return A1;
};
void insertvalue(struct arrayadt *A1,int index,int value)
{
    if(A1->capacity-1>=index){
        if(A1->lastindex==index-1){
            A1->ptr[index]=value;
            A1->lastindex++;
        }
        else
            if(index<=A1->lastindex)
                printf("\nblock is already filled:");
            else
                printf("\nyour previous index is empty so that you't enter value in this index:");
    }
    else
        printf("\nyour entered index more then capacity:");
}
void printdata(struct arrayadt *A1,int index)
{
    if(A1->capacity-1>=index)
        if(A1->lastindex>=index){
            printf("%d",A1->ptr[index]);
       }
       else{
           printf("\nblock is empty");
       }
    else{
        printf("\nyou are entered wrong index");
    }
}
void viewlist(struct arrayadt *A1)
{
    if(A1->lastindex<=-1)
        printf("\nList is empty:");
    else{
        for(int i=0;i<=A1->lastindex;i++){
            printf("\n%d",A1->ptr[i]);
        }
    }
}
void countelement(struct arrayadt *A1)
{
    printf("%d",A1->lastindex+1);
}
struct arrayadt* increase_array_size(struct arrayadt *A1,int size)
{
    A1=(struct arrayadt*)realloc(A1->ptr,size*4);
    return A1;
}
int main()
{
    int capacity,choice,index,value,size;
    struct arrayadt *A1;
    printf("\nENTER CAPACITY OF ARRAY:");
    scanf("%d",&capacity);
    A1=createarray(capacity);
    while(1){
        system("cls");
        printf("\n1.insert value in array:");
        printf("\n2.view a data");
        printf("\n3.view list:");
        printf("\n4.change size of array:");
        printf("\n5.count element of array");
        printf("\n0.EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1:
               printf("\nenter index and value");
               scanf("%d%d",&index,&value);
               insertvalue(A1,index,value);
               break;
           case 2:
               printf("\nenter index");
               scanf("%d",&index);
               printdata(A1,index);
               break;
           case 3:
               viewlist(A1);
               getch();
               break;
           case 4:
               printf("enter new size of array:");
               scanf("%d",&size);
               A1=increase_array_size(A1,size);
               printf("size successfully changed:");
               break;
           case 5:
               countelement(A1);
               break;
           case 0:
               exit(0);
           default:
               printf("\nINVALID CHOICE");
               break;
        }
        getch();
    }
}
