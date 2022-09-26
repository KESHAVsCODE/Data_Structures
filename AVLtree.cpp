#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct AVLNODE
{
    int data,height;
    struct AVLNODE *left;
    struct AVLNODE *right;
};
struct AVLNODE* createnode(int data)
{
    struct AVLNODE *temp;
    temp=(struct AVLNODE*)malloc(sizeof(struct AVLNODE));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}
struct AVLNODE* insertion(struct AVLNODE *root,int data)
{
    int a,b,c,bf;
    struct AVLNODE *temp,*n;
    temp=createnode(data);
    if(root==NULL){
        root=temp;
        return root;
    }
    else
    {
        n=root;
        while(1)
        {
            if(data<n->data&&n->left)
                n=n->left;
            else if(data>n->data&&n->right)
                n=n->right;
            else{
                if(data>n->data){
                n->right=temp;
                break;
                }
                else if(data<n->data){
                n->left=temp;
                break;
                }
                else
                    break;
            }
        }
    }
    return root;
}
struct AVLNODE* insert_recursive(struct AVLNODE *root,int data)
{
    if(root==NULL)
        return createnode(data);
    else if(data<root->data)
        root->left=insert_recursive(root->left,data);
    else if(data>root->data)
        root->right=insert_recursive(root->right,data);
    else
        return root;
}
void printdata(struct AVLNODE *root)
{
    if(root)
    {
        printdata(root->left);
        printf("%d\n",root->data);
        printdata(root->right);
    }
}
int main()
{
   struct AVLNODE *root=NULL;
   int choice,data;
   while(1)
   {
       system("cls");
       printf("\n 1. insert data");
       printf("\n 2. view all data");
       printf("\n 3. insert using recursive data");
       printf("\n 4. root value");
       printf("\n enter your choice");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("enter data");
               scanf("%d",&data);
               root=insertion(root,data);
               printf(" %u",root);
               break;
       case 2:
        printdata(root);
        break;
       case 3:
        printf("enter data");
               scanf("%d",&data);
               root=insert_recursive(root,data);
               printf(" %u",root);
               break;
       case 4:
        printf(" %u",root);
        break;
       default:
        printf("invalid choice");
        break;
       }
       getch();
    }
}
