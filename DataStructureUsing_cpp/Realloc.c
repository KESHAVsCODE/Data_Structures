#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *temp;
    temp = (int*)malloc(4);
    *temp = 1;
    printf("%d\n",*temp);

    temp = (int*)realloc(temp,8);
    *(temp+0) = 2;
    *(temp+1) = 3;

    printf("%d %d",*(temp),*(temp+1));

    return 0;
}
