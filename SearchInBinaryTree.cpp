#include<iostream>
#include<stack>
void travers(node *n,int data)
{
    if(n->data!=data)
    {
        traverse(n->left,data);
        traverse(n->right,data);
    }
}
