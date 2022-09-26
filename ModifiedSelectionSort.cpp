#include<iostream>
using namespace std;
void selectionSort(int A[],int NUM);
int main()
{
    int A[]={5,1,4,2,7},NUM=5;
    selectionSort(A,NUM);
    for(int i=0;i<NUM;i++){
        cout<<" "<<A[i];
    }
}
void selectionSort(int A[],int NUM)
{
    int temp,index1,index2,MIN;
    for(index1=0;index1<NUM;index1++){
        MIN=A[index1];
        index2=index1;
        for(int i=index1+1;i<NUM;i++){
            if(MIN>A[i]){
                MIN=A[i];
                index2=i;
            }
        }
        temp=A[index1];
        A[index1]=A[index2];
        A[index2]=temp;
    }
}
