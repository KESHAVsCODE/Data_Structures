#include<iostream>
#include<conio.h>
using namespace std;
class DLL
{
    public:
        class Node
        {
            public:
                int data;
                Node *next;
                Node *previous;
        };
        Node *Start;
        int Length;
        DLL()
        {
            Start = nullptr;
            Length = 0;
        }
        Node* createNode(int value)
        {
            Node *temp;
            temp = new Node;
            temp->data= value;
            temp->next=nullptr;
            temp->previous=nullptr;
            return temp;

        }
        void insertNodeAtFirst(int value)
        {
            Node *temp;
            temp = createNode(value);
                if(Start==nullptr)
                    Start=temp;
                else{
                    temp->next=Start;
                    Start->previous=temp;
                    Start = temp;
                }
                Length++;
        }
        void printList()
        {
            if(Start==nullptr)
                cout<<"EMPTY LIST";
            else{
                Node *shift;
                shift = Start;
            while(shift!=nullptr)
            {
                cout<<shift->data<<" ";
                shift = shift->next;
            }
            cout<<"Length Is ->"<<Length<<endl;
            }
        }
        void insertNodeAtLast(int value)
        {
            Node *temp;
            temp = createNode(value);
                if(Start==nullptr)
                    Start=temp;
                else
                {
                    Node *shift = Start;
                    while(shift->next!=nullptr)
                    {
                        shift = shift->next;
                    }
                    shift->next=temp;
                    temp->previous=shift;
                }
                Length++;
        }
        void insertByPosition(int position,int value)
        {
            int c=1;
            Node *temp;
            temp = createNode(value);
                if(position==1)
                    insertNodeAtFirst(value);
                else{
                    Node *shift = Start;
                    if(position<=Length){
                        while(c<position-1)
                        {
                            shift = shift->next;
                            c++;
                        }
                        temp->previous = shift;
                        temp->next = shift->next;
                        shift->next = temp;
                        temp->next->previous = temp;
                        Length++;
                    }
                }
        }
        void deleteAtFront()
        {
            Node *temp;
            if(Start!=nullptr){
            temp = Start;
            Start = Start->next;
            Start->previous=nullptr;
            delete temp;
            Length--;
            }
        }
        void deleteByPosition(int position)
        {
            int c=1;
            if(position==1)
                deleteAtFront();
            else{
                if(position<=Length){
                    Node *shift=Start;
                    while(c<position)
                    {
                        shift = shift->next;
                        c++;
                    }
                    if(shift->next!=nullptr)
                        shift->next->previous = shift->previous;
                    shift->previous->next = shift->next;
                    Length--;
                    delete shift;
                }
            }
        }
        void reverseList()
        {
            Node *shift=Start,*temp;
            while(shift!=nullptr)
            {
                temp = shift->previous;
                shift->previous = shift->next;
                shift->next = temp;
                shift=shift->previous;
            }
            Start = temp->previous;
        }

};
int main()
{
    DLL s;
    s.insertNodeAtFirst(1);
    s.insertNodeAtFirst(2);
    s.insertNodeAtFirst(3);
    s.insertNodeAtFirst(4);
    s.insertNodeAtLast(5);
    s.insertNodeAtLast(6);
    s.insertNodeAtLast(7);
    s.insertNodeAtLast(8);
    s.printList();
//    s.insertByPosition(1,9);
//    s.printList();
//    s.insertByPosition(10,10);
//    s.printList();
//    s.insertByPosition(9,10);
//    s.printList();
//    getch();
//    s.deleteByPosition(8);
//    s.printList();
//    getch();
//    s.deleteByPosition(1);
//    s.printList();
//    s.deleteByPosition(5);
//    s.printList();
//    s.deleteByPosition(10);
//    s.printList();
    s.reverseList();
    s.printList();

}
