#include<stdio.h>
int main()
{
    int i,j;
    for(i=16,j=0;i>0;i/=2,j+=i)
    printf("%d %d      ",i,j);
    return 0;
}
