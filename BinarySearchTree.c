#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BSTNODE
{
    int data;
    struct BSTNODE *left;
    struct BSTNODE *right;
}*root=NULL;
void insertnode(int data)
{
    struct BSTNODE *n,*temp;
    n=(struct BSTNODE*)malloc(sizeof(struct BSTNODE));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    if(root==NULL)
        root=n;
    else{
        temp=root;
        while(temp!=NULL){
            if(data<temp->data){
                if(temp->left==NULL){
                    temp->left=n;
                    break;
                }
                temp=temp->left;
            }
            else if(data>temp->data){
                if(temp->right==NULL){
                    temp->right=n;
                    break;
                }
                temp=temp->right;
            }
            else
            break;
        }

    }
}
struct BSTNODE* find(struct BSTNODE *root,int data)
{
    struct BSTNODE *temp;
    temp=root;
    if(temp==NULL)
        return NULL;
    else
    {
        while(temp!=NULL&&temp->data!=data)
        {
            if(temp->data>data)
                temp=temp->left;
            else if(temp->data<data)
                temp=temp->right;
        }
        return temp;
    }
}
struct BSTNODE* recursion_find(struct BSTNODE *root,int data)
{
    if(root==NULL)
        return NULL;
    else if(data>root->data)
            return (recursion_find(root->right,data));
    else if(data<root->data)
            return (recursion_find(root->left,data));
    return root;
}
void inorder(struct BSTNODE *root)
{
    if(root){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
struct BSTNODE* max(struct BSTNODE *root)
{
    if(root->right==NULL)
        return root;
    return max(root->right);
}
struct BSTNODE* searchNode(struct BSTNODE *root,int data)
{
      if(root==NULL)
      {
          return NULL;
      }
      else if(root->data==data)
      {
          return root;
      }
      return searchNode(root->left,data)!=NULL?searchNode(root->left,data):searchNode(root->right,data);
}
struct BSTNODE* deletion(struct BSTNODE *root,int data)
{
    struct BSTNODE *temp;
    if(root==NULL)
        printf("NO SUCH ELEMENT FIND");
    else if(data<root->data)
        root->left=deletion(root->left,data);
    else if(data>root->data)
        root->right=deletion(root->right,data);
    else if(root->left&&root->right)
    {
        temp=max(root->left);
        root->data=temp->data;
        root->left=deletion(root->left,root->data);
    }
    else{
        temp=root;
        if(root->left==NULL)
            root=root->right;
        else if(root->right==NULL)
            root=root->left;
        free(temp);
    }
    return root;
}
int main()
{
   struct BSTNODE *f;
   int choice,data;
   while(1)
   {
       system("cls");
       printf("\n 1. insert data");
       printf("\n 2. find node");
       printf("\n 3. view all data");
       printf("\n 4. find using recursion");
       printf("\n 5. find max");
       printf("\n 6. delete node data");
       printf("\n 7. SEARCH LIKE BINARY TREE");
       printf("\n 0. exit");
       printf("\n enter your choice");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
               printf("enter data");
               scanf("%d",&data);
               insertnode(data);
               break;
           case 2:
               printf("enter data");
               scanf("%d",&data);
               f=find(root,data);
                if(f!=NULL)
               printf("%u",f);
               else
                printf("element not exist:");
               break;
           case 3:
               if(root==NULL)
                printf("EMPTY");
               else
               inorder(root);
               break;
           case 4:
               printf("enter data");
               scanf("%d",&data);
               f=recursion_find(root,data);
               if(f!=NULL)
               printf("%u",f);
               else
                printf("element not exist:");
               break;
           case 5:
               f=max(root);
               if(f==NULL)
                    printf("NO ELEMENT found");
               else
                printf("%u",f);
               break;
           case 6:
                printf("enter data");
                scanf("%d",&data);
                f=deletion(root,data);
                printf(" %u",f);
                break;
           case 7:
                printf("enter data");
                scanf("%d",&data);
                f=searchNode(root,data);
                printf("%d",f->data);
                break;
           case 0:
            exit(0);
           default:
            printf("INVALID CHOICE");
            break;
       }
       getch();
   }
}
