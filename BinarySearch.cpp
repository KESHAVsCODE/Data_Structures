#include<stdio.h>
#include<conio.h>
int main()
{
    int l=0,u=9,m=0,item;
    int a[]={0,1,2,3,4,5,6,7,8,9};
    scanf("%d",&item);
    while(l<=u){
        m=(l+u)/2;
        if(item>a[m])
            l=m+1;
        else if(item<a[m])
            u=m-1;
        else{
            printf("item found");
            break;
        }
    }
    if(l>u)
    printf("\nitem not exist");
    else
    printf("\nlocation is %d",m);
}
