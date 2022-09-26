#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &arr,int rang);
int findMin(vector<int> &arr,int rang,int k);
int main()
{
    int rang;
    cout<<"Enter the size of array";
    cin>>rang;
    vector<int>arr(rang);
    for(int i=0;i<rang;i++){
        cin>>arr[i];
    }
    selectionSort(arr,rang);
    for(int i=0;i<rang;i++){
        cout<<arr[i]<<" ";
    }
}
void selectionSort(vector<int> &arr,int rang)
{
    int index,min;
    for(int i=0;i<rang;i++){
        index=findMin(arr,rang,i);
        min=arr[index];
        arr[index]=arr[i];
        arr[i]=min;
    }
}
int findMin(vector<int> &arr,int rang,int k)
{
    int MIN=arr[k],index=k;
    for(int i=k+1;i<rang;i++){
        if(MIN>arr[i]){
            MIN=arr[i];
            index=i;
        }
    }
    return index;
}
