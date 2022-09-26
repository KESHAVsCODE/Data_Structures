#include<iostream>
#include<conio.h>
using namespace std;
class SLL
{
public:
    class Node
    {
        public:
        int data;
        Node *next;
    };
    Node *Start;
    int Length;
public:
    SLL()
    {
        Length = 0;
        Start = nullptr;
    }
    Node* addTwoNumbers(Node* l1, Node* l2) {
        int Length1 = listLength(l1);
        int Length2 = listLength(l2);
        Node *temp = Length1>Length2?l1:l2;
        Node *temp1 = temp;
        int carry = 0;
        while((l1 != nullptr) && (l2 != nullptr))
        {
            if(l1->data + l2->data + carry > 9)
            {
                temp->data = l1->data + l2->data + carry - 10;
                carry = 1;
            }
            else
            {
                temp->data = l1->data + l2->data + carry;
                carry = 0;
            }
            temp = temp -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(temp!=nullptr)
        {
            if(temp->data + carry > 9)
            {
                temp->data = temp->data + carry - 10;
                carry = 1;
            }
            else
            {
                temp->data = temp->data + carry;
                carry = 0;
            }
            temp = temp -> next;
        }
        return temp1;
    }
    void insertNodeAtFirst(int value)
    {
        Node *temp;
        temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        if(Start==nullptr){
            Start=temp;
        }
        else
        {
            temp->next = Start;
            Start = temp;
        }
        Length++;
    }
    void insertNodeAtLast(int value)
    {
        Node *temp;
        temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        if(Start==nullptr)
            Start = temp;
        else{
            Node *shift;
            shift = Start;
            while(shift->next!=nullptr)
            {
                shift = shift->next;
            }
            shift->next = temp;
        }
        Length++;
    }
    void deleteNodeAtFirst()
    {
        if(Start!=nullptr){
            Node *temp;
            temp = Start;
            Start = Start->next;
            delete temp;
            Length--;
        }
    }
    void insertNodeAtPosition(int value,int position)
    {
        if(position<=Length){
        int c=0;
        Node *temp;
        temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        if(Start==nullptr)
            Start = temp;
        else{
            Node *shift;
            shift = Start;
                cout<<" "<<position<<endl;
                while(c<position-2)
                {
                    c++;
                    shift = shift->next;
                }
            temp->next = shift->next;
            shift->next = temp;
            }
            Length++;
        }
    }
    void deleteNodeAtPosition(int position)
    {
        int c=1;
        Node *temp;
        Node *shift;
        shift = Start;
        if(position==1)
            deleteNodeAtFirst();
        if(Start!=nullptr){
            if(position<=Length){
                while(c<position-1)
                {
                    shift = shift->next;
                    c++;
                }
            temp = shift->next;
            shift->next = temp->next;
            delete temp;
            Length--;
            }
        }
    }
    int listLength(Node *temp)
    {
        int l=0;
        while(temp!=nullptr)
        {
            temp = temp->next;
            l++;
        }
        return l;
    }
    void ReverseList()
    {
        Node *t1=nullptr,*t2=nullptr;
        while(Start!=nullptr){
            t1 = Start->next;
            Start->next = t2;
            t2 = Start;
            Start = t1;
        }
        Start = t2;
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
};
int main()
{
    SLL s,s1;
    s.insertNodeAtFirst(9);
    s.insertNodeAtFirst(9);
    s.insertNodeAtFirst(9);
    s.insertNodeAtFirst(9);
    s.insertNodeAtFirst(9);
    s.insertNodeAtFirst(9);
    s.insertNodeAtFirst(9);
    s1.insertNodeAtFirst(9);
    s1.insertNodeAtFirst(9);
    s1.insertNodeAtFirst(9);
    s1.insertNodeAtFirst(9);
    s.printList();
    s1.printList();

    s.addTwoNumbers(s1);

    cout<<endl;
    getch();
//    s.deleteNodeAtPosition(3);
//    s.printList();
//    s.deleteNodeAtPosition(3);
//    s.printList();
//    s.deleteNodeAtPosition(3);
//    s.printList();
//    s.deleteNodeAtPosition(3);
//    s.printList();
//    getch();
//    s.deleteNodeAtPosition(2);
//    s.printList();
//    getch();
//    s.deleteNodeAtPosition(1);
//    s.printList();
    s.ReverseList();
    s.printList();
//    s.insertNodeAtPosition(6,3);
//s.printList();
//    s.insertNodeAtPosition(7,3);
//s.printList();
//    s.insertNodeAtPosition(8,3);
//    s.printList();
// s.insertNodeAtPosition(9,8);
// s.printList();
//    s.printList();
////    s.deleteNodeAtFirst();
////    s.printList();
////    s.deleteNodeAtFirst();
////    s.printList();
////    s.deleteNodeAtFirst();
////    s.printList();
////    s.deleteNodeAtFirst();
////    s.printList();
}












