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
     {
       return NULL;
     }
     if(root->data==key)
     {
       return root;
     }
     else if(key<root->data)
     {
         return(recursives(root->left,key));
     }
     else
     {
         return(recursives(root->right,key));
     }
 }
tree *iteratives(tree *root,int key)
 {
    while(root!=NULL)
    {
        if(root->data==key)
        return root;
        else if(key<root->data)
        root=root->left;
        else
        root=root->right;
    }
 }
void insert(tree *root,int key)
{
    tree *prev=NULL;
    while(root!=NULL)
    {
        prev=root;// so prev location of root is stored before updation
        if(root->data==key)
        {
            cout<<"\n Data already exists";
            break;
        }
        else if(key<root->data)
        root=root->left;
        else
        root=root->right;
    }
    tree *neww=create(key);
    // new->data=key;
    if(key<prev->data)
    {
        prev->left=neww;
    }
    else
    {
        prev->right-neww;
    }
}
tree *inOrderPredecessor(tree* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}
tree *deleteNode(tree *root, int value){

    tree * iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        delete(root);   // root node deletion
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;//lower pre
        root->left = deleteNode(root->left, iPre->data);//left is removed since lower pre is used
    }
    return root;
}

int main()
{
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

    cout<<"\n  ***  PreOrder Traversal  ***";
    preorder(root);
    cout<<"\n  ***  PostOrder Traversal  ***";
    postorder(root);
    cout<<"\n  ***  InOrder Traversal  ***";
    inorder(root);

    
    
    tree *n = recursives(root, 55);
    if(n!=NULL)
    {
        cout<<"\n Found: "<<n->data;
    }
    else
    {
        cout<<"\nElement not found";
    }
   
    tree *n1 = iteratives(root, 70);
    if(n1!=NULL){
    cout<<"\nFound:"<< n1->data;
    }
    else{
        cout<<"\nElement not found";
    }
    
    insert(root,55);
    
    tree *n2 = iteratives(root, 55);
    if(n2!=NULL){
    cout<<"\nFound:"<< n2->data;
    }
    else{
        cout<<"\nElement not found";
    }

    deleteNode(root, 60);
    cout<<"\n  ***  InOrder Traversal  ***";
    inorder(root);


    cout<<"\n root right="<<p2->data;//to check lower pre is replaced and left is removed
    return 0;
}
