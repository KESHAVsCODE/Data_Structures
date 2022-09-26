#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      printf("%d ",fib(i));
    }
}
int fib(int n)
{
    if(n==1||n==2)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
