#include<iostream>
using namespace std;
void TOH(int,char,char,char);
int main()
{
    int n;
    cout<<"how many disk to move";
    cin>>n;
    TOH(n,'A','C','B');
}
void TOH(int n,char s,char d,char a)
{
    if(n==1)
        cout<<"move disk source %c to destini %c"<<s<<d;
    TOH(n-1,s,a,d);
    cout<<"move disk %d source %c to destini %c"<<n<<s<<d;
    TOH(n-1,a,d,s);
}
