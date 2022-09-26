#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("\n%d",fact(n));
    return 0;
}
int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
