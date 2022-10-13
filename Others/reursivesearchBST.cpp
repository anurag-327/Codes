#include<bits/stdc++.h>
using namespace std;
struct tree
{
    tree *left;
    tree *right;
    int data;
};
tree *create(int val)
{
    tree *t=new tree;
    t->data=val;
    t->left=NULL;
    t->right=NULL;
    return t;
}
void preorder(tree *root)
{
    if(root!=NULL)
    {
        cout<<" "<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data;
    }
}
void inorder(tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<" "<<root->data;
        inorder(root->right);
    }
}
 tree *recursives(tree *root,int key)
 {
     if(root==NULL)
     return NULL;
     if(root->data==key)
     return root;
     else if(root->data<key)
     return(recursives(root->left,key));
     else
     return(recursives(root->left,key));
 }
int main()
{
    tree *s=new tree;
    tree *root=create(50);
    tree *p1=create(40);
    tree *p2=create(60);
    tree *p3=create(20);
    tree *p4=create(45);
    tree *p5=create(55);
    tree *p6=create(70);
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;
   

      //        50
     //      /       \
    //     40        60
   //     /  \      /  \
  //    20    45   55   77

    cout<<"\n  ***  PreOrder Traversal  ***";
    preorder(root);
    cout<<"\n  ***  PostOrder Traversal  ***";
    postorder(root);
    cout<<"\n  ***  InOrder Traversal  ***";
    inorder(root);

    tree *n = recursives(root, 10);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    
    return 0;
}
