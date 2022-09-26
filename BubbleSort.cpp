#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int cap;
    printf("enter the size of array :");
    scanf("%d",&cap);
    vector<int>a(cap);
    for(int i=0;i<cap;i++){
        cin>>a[i];
    }
    int wap,round=cap;
    for(int i=1;i<cap;i++){
        for(int i=0;i<round-1;i++){
            if(a[i]>a[i+1]){
                wap=a[i];
                a[i]=a[i+1];
                a[i+1]=wap;
            }
        }
        round--;
    }
    for(int i=0;i<cap;i++){
        cout<<" "<<a[i];
    }
}
