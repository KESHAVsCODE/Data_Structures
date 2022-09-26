#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *p;
    p=(int*)malloc(4);
    *p=10;
    *(p+1)=20;
    *(p+2)=30;
    *(p+3)=40;
    *(p+4)=50;
    printf("%d %d %d %d %d",p[0],*(p+1),*(p+2),*(p+3),*(p+4));
}
