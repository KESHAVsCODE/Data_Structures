#include<iostream>
#include<conio.h>
using namespace std;
class Node;
class CDLL
{
    public:
        class Node
        {
        public:
            int data;
            Node *next;
            Node *previous;
        };
        Node *Last;
        int Length;
        CDLL()
        {
            Length = 0;
            Last = nullptr;
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
        void insertatfirst(int value)
        {
            Node *temp;
            temp = createNode(value);
            if(Last==nullptr){
                Last=temp->next=temp->previous=temp;
            }
            else
            {
                temp->previous=Last;
                temp->next = Last->next;
                Last->next = temp;
                temp->next->previous = temp;
            }
            Length++;
        }
        void insertatlast(int value)
        {
            Node *temp;
            temp = createNode(value);
            if(Last==nullptr){
                Last=temp->next=temp->previous=temp;
            }
            else
            {
                temp->previous=Last;
                temp->next = Last->next;
                Last->next = temp;
                temp->next->previous = temp;
                Last = temp;
            }
            Length++;
        }
        void insertByPosition(int position,int value)
        {
            int c=1;
            Node *temp;
            temp = createNode(value);
                if(position==1)
                    insertatfirst(value);
                else{
                    Node *shift = Last->next;
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
        void deletefirstnode()
        {
            if(Last==Last->next){
                Last = nullptr;
                Length--;
            }
            else
            if(Last!=nullptr)
            {
                Node *temp;
                temp = Last->next;
                Last->next = temp->next;
                temp->next->previous=Last;
                delete temp;
                Length--;
            }
        }
        void deletelastnode()
        {
            if(Last==Last->next){
                Last = nullptr;
                Length--;
            }
            else
                if(Last!=nullptr)
                {
                    Node *temp;
                    temp = Last;
                    Last = Last->previous;
                    Last->next = temp->next;
                    temp->next->previous=Last;
                    delete temp;
                    Length--;
                }

        }
        void printList()
        {
            if(Last==nullptr)
                cout<<"EMPTY LIST";
            else{
                Node *shift;
                shift = Last->next;
            do
            {
                cout<<shift->data<<" ";
                shift = shift->next;
            }while(shift!=Last->next);
            cout<<"Length Is ->"<<Length<<endl;
            }
        }
};
int main()
{
    CDLL CD;
    int i=0;
    while(i!=10){
    CD.insertatlast(i++);
    }
     CD.printList();
     cout<<" "<<i<<" ";

//    CD.insertByPosition(1,9);
//    getch();
//    CD.printList();
//    getch();
//    CD.insertByPosition(6,6);
//    CD.printList();
//    getch();
//    CD.insertByPosition(10,10);
//    CD.printList();
//    getch();
//    CD.insertByPosition(7,7
    while(i!=0){
    CD.deletelastnode();
    CD.printList();
    i--;
    }
}

