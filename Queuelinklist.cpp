#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class queue
{
private:
    struct node
    {
        int value;
        node *next;

    }*front,*rear;
public:
    queue()
    {
        front=NULL;
        rear=NULL;
    }
    void insertvalue(int data)
    {
       node *n;
       n= new node;
       n->value=data;
       n->next=NULL;
       if(rear==NULL){
        front=n;
        rear=n;
       }
       else
       {
           rear->next=n;
           rear=n;
       }
    }
    void deletequeuedata()
    {
        if(rear==NULL)
            cout<<endl<<"queue is empty:";
        else{
            node *t=front;
            if(front->next==NULL)
                rear=NULL;
            front=front->next;
            delete t;
        }

    }
    void viewqueue()
    {
        if(rear==NULL)
        {
            cout<<endl<<"queue is empty:";
        }
        else
        {
            node *t=front;
            while(t!=NULL)
            {
                cout<<endl<<t->value;
                t=t->next;
            }
        }
    }
};
int main()
{
    queue que;
    int choice,data;
    while(1)
    {
        system("cls");
        cout<<"\n 1. insert data:";
        cout<<"\n 2. delete data:";
        cout<<"\n 3. view queue:";
        cout<<"\n 0. exit:";
        cout<<"\n enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<endl<<"enter a data";
            cin>>data;
            que.insertvalue(data);
            cout<<endl<<"value inserted";
            getch();
            break;
        case 2:
            que.deletequeuedata();
            break;
        case 3:
            que.viewqueue();
            getch();
            break;
        case 0:
            exit(0);
        default:
            cout<<endl<<"INVALID CHOICE";
            break;
        }
    }
    getch();
}
