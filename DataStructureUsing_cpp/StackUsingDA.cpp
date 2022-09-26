#include<iostream>
using namespace std;
class Stack
{
    private:
        int capacity;
        int Top;
        int *SDA;
    public:
        Stack(int Size)
        {
            capacity = Size;
            SDA = new int[Size];
            Top = -1;
        }
        void Push(int value)
        {
            if(Top==capacity-1)
                cout<<"Stack Overflow"<<endl;
            else
            {
                Top++;
                SDA[Top] = value;
            }
        }
        void Pop()
        {
            if(Top==-1)
                cout<<"Stack Underflow"<<endl;
            else
                Top--;
        }
        void ResizeStack(int Size)
        {
            int *temp=SDA;
            int *t = new int[Size];
            for(int i=0;i<=Top;i++)
                t[i] = SDA[i];
            capacity = Size;
            SDA = t;
            delete temp;
        }
        void printStack()
        {
            for(int i=0;i<=Top;i++)
                cout<<SDA[i]<<" ";
            cout<<endl;
        }

};
int main()
{
    Stack s(5);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
//    s.printStack();
//    s.Pop();
//    s.printStack();
//    s.Pop();
//    s.printStack();
//    s.Pop();
//    s.printStack();
//    s.Pop();
//    s.printStack();
//    s.Pop();
//    s.printStack();
//    s.Pop();
    s.printStack();
    s.ResizeStack(7);
    s.Push(6);
    s.Push(7);
    s.Push(8);
    s.Push(9);
    s.Push(10);
    s.printStack();
    return 0;
}
