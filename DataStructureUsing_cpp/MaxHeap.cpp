#include<iostream>
#include<conio.h>
using namespace std;
int ExtractMax(int *a,int Size)
{
    int i=0,temp1,temp;
    temp1 = a[i];
    a[i] = a[Size];
    while(i<Size)
    {
        if(a[i]<2*i+1 || a[i]<2*i+2)
            if(a[2*i+1]<a[2*i+2])
            {
                temp = a[i];
                a[i] = a[2*i+2];
                a[2*i+2] = temp;
                i = 2*i+2;
            }
            else
            {
                temp = a[i];
                a[i] = a[2*i+1];
                a[2*i+1] = temp;
                i = 2*i+1;
            }
    }
    return temp1;
}
int main()
{
    int a[7];
    int data,i;
    for(int j=0;j<7;j++){
        cin>>a[j];
        i=j;
        while(a[i]>a[(i-1)/2])
        {
            static int temp;
                temp = a[i];
                a[i]=a[(i-1)/2];
                a[(i-1)/2]= temp;
            i=(i-1)/2;
        }
    }
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";

    for(int j=0;j<7;j++)
        cout<<ExtractMax(a,7)<<" ";
    return 0;
}
