#include<iostream>
#include<queue>
#include<conio.h>
using namespace std;
class BST
{
    private:
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
        void levelOrderTraversal()
        {
            Node *temp=Root;
            queue<Node*> que;
            if(!Root)
                cout<<"EMPTY";
            else{
                que.push(Root);
                while(!que.empty())
                {
                    temp = que.front();
                    cout<<temp->data<<" ";
                    que.pop();
                    if(temp->left)
                        que.push(temp->left);
                    if(temp->right)
                        que.push(temp->right);
                }
            }
        }
        int heightOfBST(Node *root)
        {
            if(root==nullptr)
                return -1;
            else{
                int LH = heightOfBST(root->left);
                int RH = heightOfBST(root->right);
                if(LH>RH)
                    return 1+LH;
                else
                    return 1+RH;
            }
        }
        void printBST(Node *temp)
        {
            if(!temp)
                return;
            printBST(temp->left);
            cout<<temp->data<<"->";
            printBST(temp->right);
        }
        Node* FindNode(Node *root,int data)
        {
            if(root==nullptr)
                return root;
            else if(data<root->data)
                return FindNode(root->left,data);
            else if(data>root->data)
                return FindNode(root->right,data);
            else
                return root;
        }
        void insertInBST(int data)
        {
            Root = insertInBST(Root,data);
        }
        Node* insertInBST(Node *flag,int data)
        {
            if(!flag)
                return createNode(data);
            else if(data<flag->data)
            {
                flag->left=insertInBST(flag->left,data);
            }
            else if(data>flag->data)
            {
                flag->right=insertInBST(flag->right,data);
            }
            else{
                cout<<"ALREADY EXISt";
                return flag;
            }
        }
        Node* MaxNode(Node *temp)
        {
            if(temp->right==nullptr)
                return temp;
            return MaxNode(temp->right);
        }
        void deleteInBST(int data)
        {
            Root = deleteInBST(Root,data);
        }
        Node* deleteInBST(Node *root,int data)
        {
            if(!root)
                cout<<"NOT EXIST";
            else if(data<root->data)
                root->left = deleteInBST(root->left,data);
            else if(data>root->data)
                root->right = deleteInBST(root->right,data);
            else if(root->left&&root->right)
            {
                Node *temp;
                temp = MaxNode(root->left);
                root->data = temp->data;
                root->left = deleteInBST(root->left,root->data);
            }
            else
            {
                Node *temp=root;
                if(root->right==nullptr)
                    root = root->left;
                else
                    root = root->right;
                delete temp;
            }
            return root;
        }

};
int main()
{
    BST b;
    b.insertInBST(10);
    b.insertInBST(5);
    b.insertInBST(15);
    b.insertInBST(4);
    b.insertInBST(6);
    b.insertInBST(13);
    b.insertInBST(17);
    b.insertInBST(11);
    b.insertInBST(14);
    b.insertInBST(20);
    b.printBST(b.Root);
    cout<<endl;
    getch();
    b.levelOrderTraversal();
    cout<<endl;
    cout<<b.heightOfBST(b.Root);
//    b.insertInBST(100);
//    b.insertInBST(50);
//    b.insertInBST(1000);
//    b.insertInBST(75);
//    b.insertInBST(10);
//    b.insertInBST(55);
//    b.insertInBST(88);
//    b.insertInBST(500);
//    b.insertInBST(200);
//    b.insertInBST(700);
//    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(100);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(50);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(1000);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(75);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(10);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(55);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(88);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(500);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(200);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.deleteInBST(700);
////    b.printBST(b.Root);
////    cout<<endl;
////    b.printBST(b.Root);

}
