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

vector<vector<int>> levelorder(tree *root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    return ans;
    queue<tree*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> level; 
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            tree *node=q.front();
            q.pop();
            if(node->left!=NULL)
            q.push(node->left);
            if(node->right!=NULL)
            q.push(node->right);
            level.push_back(node->data);
            // cout<<node->data<<" ";
        }
        // cout<<endl;
        ans.push_back(level);
    }
    return ans;
}

int heightoftree(tree *node)
{
    if(node==NULL)
    return 0;
    int lh=heightoftree(node->left);
    int rh=heightoftree(node->right);
    return (1+max(lh,rh));
}

bool issame(tree *p,tree*q)
{
    if(p==NULL||q==NULL)
    {
        return(p==q)
    }
    return(p->data==q->data&&issame(p->left,p->right)&&issame(q->left,q->right));
}
int main()
{
    tree *root=create(45);
    tree *p1=create(56);
    tree *p2=create(78);
    tree *p3=create(23);
    tree *p4=create(86);
    tree *p5=create(34);
    tree *p6=create(13);
    root->right=p2;
    root->left=p1;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;
   

      //        45
     //      /       \
    //     56        78
   //     /  \      /  \
  //    23    86   34   13

    // cout<<"\n  ***  PreOrder Traversal  ***";
    // preorder(root);
    // cout<<"\n  ***  PostOrder Traversal  ***";
    // postorder(root);
    // cout<<"\n  ***  InOrder Traversal  ***";
    // inorder(root);
   

     cout<<"level order traversal*****\n";
     vector<vector<int>> k;
     k=levelorder(root);
     for(int i=0;i<k.size();i++)
     {
        for(int j=0;j<k[i].size();j++)
        {
        cout<<k[i][j]<<" ";
        }
        cout<<endl;
     }

     int p=heightoftree(root);
     cout<<endl<<p;
   return 0;
}