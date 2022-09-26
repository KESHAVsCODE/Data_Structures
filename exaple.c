#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *a,i,j;
    a=malloc(sizeof(int)*4*4);

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            a[i][j]=0;
    i=0;j=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            printf("%d ",a[i][j]);
}
