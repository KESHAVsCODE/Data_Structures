#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p;
    p=(int*)malloc(4);
    /*p=10;
    *(p+1)=20;
    *(p+2)=30;
    *(p+3)=40;*/
    printf("%d %d",*p,*(p+1));
    p=(int*)realloc(p,8);
    printf("\n %d %d %d",p[0],p[1],p[2]);
    free(p);

}

