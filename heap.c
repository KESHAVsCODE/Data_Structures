#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
static int i=0,j=1;
int* insertion(int *p,int data)
{
    int k=i;
    p[k]=data;
    while(k!=0)
    {
        if(p[(k-1)/2]<data){
            p[k]=p[(k-1)/2];
            k=(k-1)/2;
        }
        else
            break;
    }
    p[k]=data;
    p=(int*)realloc(p,4*(j+1));
    i++;
    j++;
    return p;
}
void printdata(int *p)
{
    for(int k=0;k<i;k++)
    {
       printf("%d ",p[k]);
    }
}
int main()
{
    int choice;
    int *p,data;
    p=(int*)calloc(1,4);
    while(1)
    {
        system("cls");
        printf("1. insert data\n");
        printf("2. print data\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
           printf("enter data");
           scanf("%d",&data);
           p=insertion(p,data);
           break;
        case 2:
            printdata(p);
            getch();
            break;
        default:
            printf("INVALID CHOICE");
            break;
        }
    }
}
