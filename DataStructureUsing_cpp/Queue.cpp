#include<iostream>
#include<conio.h>
using namespace std;
class Queue
{
    private:
        int Front,Rear;
        int capacity;
        int *que;
    public:
        Queue(int Size)
        {
            Front = Rear = -1;
            capacity = Size;
            que = new int[Size];
        }
        int emptyQueue()
        {
            return (Front==-1);
        }
        int fullQueue()
        {
            return ((Rear+1)%capacity==Front);
        }
        void doubleQueue()
        {
            int *temp;
            temp = new int[2*capacity];
            for(int i=Front,j=0;j<capacity;j++)
            {
                temp[j] = que[i];
                if(i==capacity-1)
                    i = 0;
                else
                    i++;
            }
            Rear = capacity - 1;
            Front = 0;
            capacity = 2*capacity;
            delete que;
            que = temp;
        }
        void halfQueue()
        {
            int *temp;
            temp = new int[capacity/2];
            for(int i=Front,j=0;j<capacity/2;j++)
            {
                temp[j] = que[i];
                if(i==capacity-1)
                    i=0;
                else
                    i++;
            }
            capacity = capacity/2;
            delete que;
            que = temp;
            Front = 0;
            Rear = capacity-1;
        }
        void insertInQueue(int value)
        {
            if(Front==-1)
            {
                Front=Rear=0;
            }
            else if(fullQueue()){
                doubleQueue();
                Rear++;
            }
            else{
                if(Rear==capacity-1)
                    Rear = 0;
                else
                    Rear++;
            }
            que[Rear]=value;
        }
        void deleteInQueue()
        {
            int l=0;
            if(emptyQueue())
                cout<<"Queue is Empty";
            else if(Front==Rear)
                Front=Rear=-1;
            else if(Front==capacity-1)
                Front=0;
            else
                Front++;
            if(Front>-1){
                for(int i=Front;i!=Rear;)
                {
                    l++;
                    if(i==capacity-1)
                        i=0;
                    else
                        i++;
                }
                l++;
                if(l==capacity/2)
                    halfQueue();
            }
        }
        void printQueue()
        {
            if(Front==-1)
                cout<<"Queue Is Empty";
            else{
                int i=0;
                for(i=Front;i!=Rear;)
                {
                    cout<<que[i]<<" ";
                    if(i==capacity-1)
                        i=0;
                    else
                        i++;
                }
                cout<<que[i];
            }
                cout<<endl;
                cout<<"Rear -> "<<Rear<<endl;
                cout<<"Front -> "<<Front<<endl;
                cout<<endl<<"Queue Capacity is -> "<<capacity;
        }
};
int main()
{
    Queue Q(1);
    while(true)
    {
        system("cls");
        cout<<"1. Insert in Queue"<<endl;
        cout<<"2. Delete in Queue"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Your Choice"<<endl;
        int c;
        cin>>c;
        switch(c){
            case 1:
                int value;
                cin>>value;
                Q.insertInQueue(value);
                break;
            case 2:
                Q.deleteInQueue();
                break;
            case 3:
                Q.printQueue();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"INVALID CHOICE"<<endl;
                break;
        }
        getch();

    }
    return 0;
}
