#include<bits/stdc++.h>
using namespace std;
struct tree
{
    tree *left;
    tree *right;
    int data;
};
int k=0;
tree *create(int val)
{
    tree *t=new tree;
    t->data=val;
    t->left=NULL;
    t->right=NULL;
    return t;
}

int inorder(tree *root,int a[],int k)
{
    if(root!=NULL)
    {
        inorder(root->left,a);
        a[k]=root->data;
        k++;
        inorder(root->right,a);
    }
    return k;
}
int main()
{
    int a[6]={0};
    int b[5]={0};
    tree *s=new tree;
    tree *root=create(50);
    tree *p1=create(40);
    tree *p2=create(60);
    tree *p3=create(20);
    tree *p4=create(45);
    // tree *p5=create(55);
    tree *p6=create(70);
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=NULL;
    p2->right=p6;
   
    //    given below is BST
      //        50
     //      /       \
    //     40        60
   //     /  \      /  \
  //    20    45   55   70

    

    tree *roots=create(50);
    tree *p1s=create(40);
    tree *p2s=create(60);
    tree *p3s=create(20);
    tree *p4s=create(45);
    roots->left=p1s;
    roots->right=p2s;
    p1s->left=p3s;
    p1s->right=p4s;
    cout<<"\n  ***  InOrder Traversal  ***";
    int n1=inorder(root,a);
    k=0;
    cout<<"\n  ***  InOrder Traversal  ***";
    int n2=inorder(roots,b);
    
    for(int i=0;i<=n1;i++)
    {
        sum=0;
        for(int j=i;j<=n2;j++)
        {
           sum=sum+a[j];
        }
    }

}
