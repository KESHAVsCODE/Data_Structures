#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a=2,*b,**c,***d;
    b=18446744073709551614;// a-> 1000
/*    b=&a;
    c=&b;
    d=&c;
    ***d=3;
    printf("%d ",a);
    printf("%d ",&a);
    printf("%u ",b);
    printf("%u ",&b);
    printf("%u ",c);
    printf("%u ",&c);
    printf("%u ",**d);*/

    printf("%u",b);
}
