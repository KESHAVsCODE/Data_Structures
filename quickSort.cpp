#include<iostream>
using namespace std;
void QuickSort(int A[],int lb,int ub);
int Partition(int A[],int lb,int ub);
void Swap(int &a,int &b);
int main()
{
    int A[]={2   ,   3 ,     5  ,    7,     11,     13 ,    17     ,19     ,23,     29
             ,31     ,37     ,41     ,43     ,47,     53,     59     ,61,     67,     71
             ,73     ,79     ,83     ,89     ,97    ,101    ,103    ,107    ,109    ,113
            ,127    ,131    ,137    ,139    ,149    ,151    ,157    ,163    ,167    ,173
            ,179    ,181    ,191    ,193    ,197},NUM=45;
    QuickSort(A,0,NUM-1);
    cout<<endl;
    for(int i=0;i<NUM;i++){
        cout<<A[i]<<" ";
    }
}
void Swap(int &a,int &b)
{
    int c;
    c=a; a=b; b=c;
}
void QuickSort(int A[],int lb,int ub)
{
    int LOC;
    if(lb<ub){
        LOC=Partition(A,lb,ub);
        QuickSort(A,lb,LOC-1);
        QuickSort(A,LOC+1,ub);
    }
}
int Partition(int A  [],int lb,int ub)
{
    int Start,End,Pivot;
    Start=lb+1; End=ub; Pivot=A[lb];
    while(Start<End){
        while(Start<=ub&&A[Start]<=Pivot){
            Start++;
        }
        while(A[End]>Pivot){
            End--;
        }
        if(Start<End){
            Swap(A[Start],A[End]);

        }
//        for(int i=0;i<45;i++)
//                cout<<A[i]<<" ";
//            cout<<endl;
    }
    Swap(A[lb],A[End]);
//    for(int i=0;i<45;i++)
//                cout<<A[i]<<" ";
//            cout<<endl<<endl;
    return End;
}

