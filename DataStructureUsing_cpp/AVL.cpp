#include<iostream>
#include<queue>
#include<vector>
#include<conio.h>
using namespace std;
class AVL
{
    public:
        class Node
        {
            public:
                int data;
                Node *left;
                Node *right;
        };
    public:
        Node *Root=nullptr;
        Node* createNode(int data)
        {
            Node *temp = new Node;
            temp->data = data;
            temp->left = nullptr;
            temp->right = nullptr;
            return temp;
        }
        int heightOfAVL(Node *root)
        {
            if(root==nullptr)
                return -1;
            else{
                int LH = heightOfAVL(root->left);
                int RH = heightOfAVL(root->right);
                if(LH>RH)
                    return 1+LH;
                else
                    return 1+RH;
            }
        }
        int getBalanceFactor(Node *temp)
        {
            if(temp==nullptr)
                return -1;
            else
                return heightOfAVL(temp->left)-heightOfAVL(temp->right);
        }
        Node* rightRotate(Node *temp)
        {
            Node *X = temp->left;

            temp->left = X->right;
            X->right   = temp;
            return X;
        }
        Node* leftRotate(Node *temp)
        {
            Node *X = temp->right;

            temp->right = X->left;
            X->left     = temp;
            return X;
        }
        void insertInAVL(int data)
        {
            Root  = insertInAVL(Root,data);
        }
        Node* insertInAVL(Node *flag,int data)
        {
            if(!flag)
                return createNode(data);
            else if(data<flag->data)
            {
                flag->left=insertInAVL(flag->left,data);
            }
            else if(data>flag->data)
            {
                flag->right=insertInAVL(flag->right,data);
            }
            else if(data==flag->data){
                return flag;
            }
            int BF = getBalanceFactor(flag);
            cout<<"BF->"<<BF<<" ";
            if(BF>1 && data<flag->left->data){
                return rightRotate(flag);
            }
            else if(BF>1 && data>flag->left->data){
                flag->left = leftRotate(flag->left);
                return rightRotate(flag);
            }
            else if(BF<-1 && data>flag->right->data){
                return leftRotate(flag);
            }
            else if(BF<-1 && data<flag->right->data){
                flag->right = rightRotate(flag->right);
                return leftRotate(flag);
            }
        return flag;
        }
        bool rooToNodePath(Node *root,int t,vector<Node*> &v)
        {
            if(root==nullptr)
                return true;
            v.push_back(root);
            if(root->data==t)
                return false;
            else
            {
                bool b1,b2;
                b1 = rooToNodePath(root->left,t,v);
                if(b1)
                    b2 = rooToNodePath(root->right,t,v);
                if(b1 && b2)
                {
                    v.pop_back();
                    return true;
                }
                return false;
            }
        }
        void printAVL(Node *temp)
        {
            if(!temp)
                return;
            printAVL(temp->left);
            cout<<temp->data<<"->";
            printAVL(temp->right);
        }
};
int main()
{
    AVL avl;
    int c=0;
    while(c!=1000)
    {
        cout<<"enter a value";
        cin>>c;
        avl.insertInAVL(c);
        getch();
        cout<<"height->"<<avl.heightOfAVL(avl.Root)<<endl;
    }
    avl.printAVL(avl.Root);
    cout<<endl;
    cin>>c;
    vector<AVL::Node*> v;
    avl.rooToNodePath(avl.Root,c,v);
    for(auto &x: v)
        cout<<x->data<<" ";
    getch();

}
