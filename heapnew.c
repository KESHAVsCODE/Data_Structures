#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Heap
{
    int index;
    int size;
    int *hp;
};
struct Heap* createHeap(int size)
{
    struct Heap *p;
    p=(struct Heap*)malloc(sizeof(struct Heap));
    p->hp=(int*)malloc(4*size);
    p->index=-1;
    p->size=size;
    return p;
}
struct Heap* insertData(struct Heap *heap,int data)
{
    if(heap->index==heap->size-1)
        printf("heap is full");
    else{
        int i=++heap->index;
        while(i!=0){
            if(data>heap->hp[(i-1)/2]){
                heap->hp[i]=heap->hp[(i-1)/2];
                i=(i-1)/2;
            }
            else
                break;
        }
        heap->hp[i]=data;
    }
    return heap;
}
struct Heap* deleteData(struct Heap *heap)
{
    int t1,t2,i=0,data;
    data=heap->hp[i]=heap->hp[heap->index];
    while(2*i+2<heap->index)
    {
        t1=2*i+1;
        t2=2*i+2;
        if(heap->hp[t1]>=heap->hp[t2]){
            if(heap->hp[t1]>heap->hp[i]){
                heap->hp[i]=heap->hp[t1];
                heap->hp[t1]=data;
                i=2*i+1;
            }
        }
        else{
            if(heap->hp[t2]>heap->hp[i]){
                heap->hp[i]=heap->hp[t2];
                heap->hp[t2]=data;
                i=2*i+2;
            }
        }
    }
    if(heap->index!=-1)
    heap->index--;
}
void printData(struct Heap *heap)
{
    int i=0;
    if(heap->index==-1)
        printf("\nEmpty");
    else
    while(i<=heap->index)
    {
        printf("\n%d",heap->hp[i++]);
    }
}
void main()
{
    struct Heap *heap;
    int size,choice,data;
    printf("enter the size of heap");
    scanf("\n%d",&size);
    heap=createHeap(size);
    while(1)
    {
     system("cls");
     printf("\n 1.insert data");
     printf("\n 2.delete data");
     printf("\n 3.print data");
     printf("\n 4.index data");
     printf("\n enter your choice");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:
           printf("enter data");
           scanf("%d",&data);
           heap=insertData(heap,data);
           break;
        case 2:
           heap=deleteData(heap);
           break;
        case 3:
            printData(heap);
            getch();
            break;
        case 4:
            printf("\n%d",heap->index);
            break;
        default:
            printf("INVALID CHOICE");
            break;
    }
    getch();
    }
}




