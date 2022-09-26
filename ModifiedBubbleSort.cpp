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
    for(int j=1;j<cap;j++){
        int flag=0;
        for(int i=0;i<round-1;i++){
            if(a[i]>a[i+1]){
                flag=1;
                wap=a[i];
                a[i]=a[i+1];
                a[i+1]=wap;
            }
        }
        if(flag==0){
            return 1;
        }
        round--;
    }
    for(int i=0;i<cap;i++){
        cout<<" "<<a[i];
    }
}

