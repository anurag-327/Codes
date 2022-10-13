#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "  ";
        inorder(root->right);
    }
}

Node *search(Node *root,int key)
{
    // Node *Node;
    while(root!=NULL&&root->data!=key)
    {
        root=key<root->data?root=root->left:root->right;
    }
    return root;
}
int ceil(Node *root,int key)
{
   int ceil=-1;
   while(root)
   {
    if(root->data==key)
    {
        ceil=root->data;
        return ceil;
    }
    if(root->data<key)
    {
        root=root->right;
    }
    else
    {
        ceil=root->data;
        root=root->left;
    }
   }
   return ceil;
}
int floor(Node *root,int key)
{
   int floor=-1;
   while(root)
   {
    if(root->data==key)
    {
        floor=root->data;
        return floor;
    }
    if(root->data<key)
    {
        floor=root->data;
        root=root->right;
    }
    else
    {
        root=root->left;
    }
   }
   return floor;
}

bool isBST(Node *root,int minval,int maxval)
{
    if(root==NULL)
    return true;
    if(root->data>=maxval||root->data<minval)
    return false;
    return(isBST(root->left,minval,root->data)&&isBST(root->right,root->data,maxval));
}

int main()

{
    /*
                4
              /    \
             2       6
           /   \   /   \
         1      3  5    7
    */

    Node *root = new Node(4);
    Node *t2 = new Node(2);
    Node *t3 = new Node(6);
    Node *t4 = new Node(1);
    Node *t5 = new Node(3);
    Node *t6 = new Node(5);
    Node *t7 = new Node(7);
    root->left = t2;
    root->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;

    cout<<"Inorder Traversal="<<endl;
    inorder(root);
    cout<<endl<<"ceil="<<ceil(root,9);
    cout<<endl<<"floor="<<floor(root,9);
    cout<<endl<<isBST(root,-1,10);
    return 0;
}
