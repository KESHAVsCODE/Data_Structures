#include<stdio.h>
#include<conio.h>
int main()
{
    int n,m;
    printf("enter two number to find GCD");
    scanf("%d%d",&n,&m);
    printf("%d",GCD(n,m));
}
int GCD(int n,int m)
{
    if(n==m)
        return n;
    if(n%m==0)
        return m;
    if(m%n==0)
        return n;
    if(m>n)
        return GCD(m%n,n);
    else
        return GCD(m,n%m);
}
