#include<iostream>
using namespace std;
int main()
{
    int **p;
    p= new int*[3];
    p[0]=new int[3];
    p[1]=new int[3];
    p[2]=new int[3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            p[i][j]=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<3;i++)
        cout<<p[i]<<" ";
    cout<<endl<<p<<endl;
    for(int i=0;i<3;i++)
        delete[] p[i];
    delete[] p;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<p[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<3;i++)
        cout<<p[i]<<" ";
    cout<<endl<<p<<endl;
}

