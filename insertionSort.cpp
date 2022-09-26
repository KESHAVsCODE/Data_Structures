#include<iostream>
using namespace std;
void insertionSort(int A[],int NUM);
int main()
{
    int A[]={5,1,4,2,7},NUM=5;
    insertionSort(A,NUM);
    for(int i=0;i<NUM;i++){
        cout<<" "<<A[i];
    }
}
void insertionSort(int A[],int NUM)
{
    int i,j,temp;
    for(i=0;i<NUM;i++){
        temp=A[i];
        for(j=i-1;j>=0&&temp<A[j];j--)
            A[j+1]=A[j];
        A[j+1]=temp;
    }
}
