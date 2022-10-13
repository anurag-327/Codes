#include <bits/stdc++.h>
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

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "  ";
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << "  ";
        inorder(root->right);
    }
}

vector<vector<int>> levelorder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *n = q.front();
            q.pop();
            if (n->left != NULL)
                q.push(n->left);
            if (n->right != NULL)
                q.push(n->right);
            level.push_back(n->data);
        }
        ans.push_back(level);
    }
}

// ZIGZAG Traversal
// we main main a flag keep changing it at every level and revese and insert

vector<vector<int>> zigzag(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *n = q.front();
            q.pop();
            if (n->left != NULL)
                q.push(n->left);
            if (n->right != NULL)
                q.push(n->right);
            level.push_back(n->data);
        }
        flag = !flag;
        if (flag == false)
        {
            reverse(level.begin(), level.end());
            // cout<<level[0];
            // cout<<level[1];
        }
        ans.push_back(level);
    }
}

//    BOUNDARY TRAVERSAL
//        root
//    1-Left boundary
//    2-leaf nodes
//     3-Right Boundary in reverse

void leftboundary(Node *root, vector<int> &ans)
{
    Node *current = root->left;
    while (current)
    {
        if (current->left != NULL && current->right != NULL)
            ans.push_back(current->data);
        if (current->left != NULL)
            current = current->left;
        else
            current = current->right;
    }
}

void rightboundary(Node *root, vector<int> &ans)
{
    Node *current = root->right;
    vector<int> temp;
    while (current)
    {
        if (current->left != NULL && current->right != NULL)
            temp.push_back(current->data);
        if (current->right != NULL)
            current = current->right;
        else
            current = current->left;
    }
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
        ans.push_back(temp[i]);
    }
}

void leafnode(Node *root, vector<int> &ans)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        leafnode(root->left, ans);
    if (root->right)
        leafnode(root->right, ans);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    if (root->left != NULL && root->right != NULL)
    {
        ans.push_back(root->data);
    }
    leftboundary(root, ans);
    leafnode(root, ans);
    rightboundary(root, ans);
    return ans;
}

//            vertical order traversAL
// obtained by drawing vertical lines passing through node
// on left v dec by -1 and l inc by 1
// on right v inc by 1 and l inc 1
// use map<int,map<int,multiset<int>>>
// queue<pair<Node *,pair<int,int>>

vector<vector<int>> verticaltraversal(Node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Node *node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        // cout<<nodes[x][y].second;
        if (node->left != NULL)
            todo.push({node->left, {x - 1, y + 1}});
        if (node->right != NULL)
            todo.push({node->right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            // int k=p.second.second;
            // col.push_back(k);
            col.insert(col.end(), q.second.begin(), q.second.end());
            // cout<<q.second<<endl;
        }
        // cout<<endl;
        // for(int r=0;r<col.size();r++)
        // {
        //     cout<<col[r];
        // }
        ans.push_back(col);
    }
    return ans;
}

vector<int> topview(Node *root)
{
    map<int, int> m;
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if (m.find(line) == m.end()) // if level exists then donot add to vector
            m[line] = node->data;

        if (node->left != NULL)
            q.push({node->left, line + 1});

        if (node->right != NULL)
            q.push({node->right, line + 1});
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> bottomview(Node *root)
{
    map<int, int> m;
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        // add to vector so larger value is replaced since we are seeing from bottom
        m[line] = node->data;

        if (node->left != NULL)
            q.push({node->left, line + 1});

        if (node->right != NULL)
            q.push({node->right, line + 1});
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

void leftview(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    leftview(root->left, ans, level + 1);
    leftview(root->right, ans, level + 1);
}

void rightview(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    rightview(root->right, ans, level + 1);
    rightview(root->left, ans, level + 1);
}

bool issame(Node *p, Node *q)
{
    if (p == NULL || q == NULL)
    {
        return (p == q);
    }
    return (p->data == q->data && issame(p->left, q->left) && issame(p->right, q->right));
}

bool issymmetrical(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    if (left->data != right->data)
        return false;

    return (issymmetrical(left->left, right->left) && issymmetrical(left->right, right->right));
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    // cout<<"\nHeight of "<<root->data<<"="<<1+max(lh,rh);
    return (1 + max(lh, rh));
}

// balanced tree is one whose diff of lh and rh is <1

// basic approach go to alll node and find lh and rh and confirm situation and then call function
// child nodes

// O(N^2) approach

bool balancedtree(Node *root)
{
    if (root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 && balancedtree(root->left) && balancedtree(root->right))
        return true;

    return false;
}

// Efficient Approach
// while finding height chech situation if satisfies return height else -1
// O(N) Approach

int balancedtree2(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = balancedtree2(root->left);
    int rh = balancedtree2(root->right);

    if (lh == -1 || rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    // cout<<"\nHeight of "<<root->data<<"="<<1+max(lh,rh);
    return (1 + max(lh, rh));
}

bool getpathfromroot(Node *root,vector<int>& ans,int x)
{
    if(!root)
    return false;

    ans.push_back(root->data);
    if(root->data==x)
    return true;
    if(getpathfromroot(root->left,ans,x)||getpathfromroot(root->right,ans,x))
    return true;

    ans.pop_back();

    return false;
}

 Node *lowestCommonAncestor(Node* root, Node* p, Node* q) 
 {
        if(root==NULL||root==p ||root==q)
            return root;
        Node *left = lowestCommonAncestor(root->left,p,q);
        Node *right = lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL )
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
}
// Diameter of tree
// it is the longest path in tree
// Not necessary to pass through root
// Naive approach

// keep record of max of height then call it for child
// O(N^2)

int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return (max((1 + lh + rh), max(ld, rd)));
}

// efficient approach is to maintain maxi at time of using height function
// O(N) Approach

int diameter2(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lh = diameter2(root->left, maxi);
    int rh = diameter2(root->right, maxi);

    maxi = max(maxi, (1 + lh + rh));
    return (1 + max(lh, rh));
}

// Child Sum Property

void reorder(Node *root)
{
    if(root==NULL)
    return;

    int child=0;
    if(root->left)
    child+=root->left->data;
    if(root->right)
    child+=root->right->data;
    if(child>=root->data)
    root->data=child;
    else
    {
        if(root->left)
        root->left->data=root->data;
        else if(root->right)
        root->right->data=root->data;
    }
    reorder(root->left);
    reorder(root->right);

    int tot=0;
    if(root->left) tot=root->left->data;
    if(root->right) tot=root->right->data;
    if(root->left||root->right)
    root->data=tot;
}

// COUNT NO OF NODES 

int findleftht(Node *root)
{
    int h=0;
    while(root)
    {
        h++;
        root=root->left;
    }
    return h;
}
int findrightht(Node *root)
{
    int h=0;
    while(root)
    {
        h++;
        root=root->left;
    }
    return h;
}

int countnode(Node *root)
{
    if(root==NULL)
    return 0;
    int lh=findleftht(root);
    int rh=findrightht(root);
    if(lh==rh)
    return(pow(2,lh)-1);
    else
    return(1+countnode(root->left)+countnode(root->right));
}

// creting tree fron inorder and preorder traversal

// Node *buildtree1(vector<int> preorder, vector<int> inorder)
// {
//    map<int,int> imap;
//    for(int i=0;i<inorder.size();i++)
//    {
//     imap[inorder[i]]=i;
//    }
//    Node *root=buildtree2(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,imap);
// }
 
// Node *buildtree2(vector<int>preorder, int prestart,int preend,vector<int> inorder,int instart,int inend,map<int,int>imap) 
// {
//     if(prestart>preend|| instart>inend)
//     return NULL;

//     Node *root=new Node(preorder[prestart]);
//     int inroot=imap[root->data];
//     int numsleft=inroot-instart;

//     root->left=buildtree2(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,imap);
//     root->right=buildtree2(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,imap);
//     return root;
// }
// creting tree from inorder and postorder

// Node *buildtree3(vector<int> postorder, vector<int> inorder)
// {
//    map<int,int> imap;
//    for(int i=0;i<inorder.size();i++)
//    {
//     imap[inorder[i]]=i;
//    }
//    Node *root=buildtree3(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,imap);
// }
 
// Node *buildtree4(vector<int>postorder, int poststart,int postend,vector<int> inorder,int instart,int inend,map<int,int>imap) 
// {
//     if(poststart>postend|| instart>inend)
//     return NULL;

//     Node *root=new Node(postorder[postend]);
//     int inroot=imap[root->data];
//     int numsleft=inroot-instart;

//     root->left=buildtree4(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,imap);
//     root->right=buildtree4(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,imap);

//     return root;
// }

int main()

{
    /*
                1
              /    \
             2       3
           /   \   /   \
         4      5  6    7
    */

    Node *root = new Node(1);
    Node *t2 = new Node(2);
    Node *t3 = new Node(3);
    Node *t4 = new Node(4);
    Node *t5 = new Node(5);
    Node *t6 = new Node(6);
    Node *t7 = new Node(7);
    root->left = t2;
    root->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;
    // reorder(root);

    //   Preorder Traversal
    cout <<endl<< "Preorder Traversal" << endl;
    preorder(root);

    //  postorderTraversal
    cout << endl
         << "\nPostorder Traversal" << endl;
    postorder(root);

    // Inorder Traversal
    cout << endl
         << "\nInOrder Traversal" << endl;
    inorder(root);

    // Levelorder Traversal

    cout << endl
         << "\nLevel order Traversal" << endl;
    vector<vector<int>> g;
    g = levelorder(root);
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << "  ";
        }
        cout << endl;
    }

    //   zig zag Traversal

    cout << "\nzigzag Traversal" << endl;
    vector<vector<int>> k;
    k = zigzag(root);
    for (int i = 0; i < k.size(); i++)
    {
        for (int j = 0; j < k[i].size(); j++)
        {
            cout << k[i][j] << "  ";
        }
        cout << endl;
    }

    //   BOUNDARY TRAVERSAL
    cout << endl
         << "Boundary Traversal" << endl;
    vector<int> ans;
    ans = boundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }

    // Vertical Order traversal

    cout << endl
         << "\nVertical Order Traversal" << endl;
    vector<vector<int>> d;
    d = verticaltraversal(root);
    for (int i = 0; i < d.size(); i++)
    {
        for (int j = 0; j < d[i].size(); j++)
        {
            cout << d[i][j] << "  ";
        }
        cout << endl;
    }

    // Top view of tree

    cout << endl
         << "\nTop  View of tree" << endl;

    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i][0] << "  ";
        // cout << endl;
    }
    cout << endl;
    //   cout<<endl<<"\nTop  View of tree"<<endl;
    vector<int> a;
    a = topview(root);
    for (int e = 0; e < a.size(); e++)
    {
        cout << a[e] << "  ";
    }

    //  Bottom view of tree

    cout << endl
         << "\nBottom View of tree" << endl;

    for (int i = 0; i < d.size(); i++)
    {
        int u = d[i].size() - 1;
        cout << d[i][u] << "  ";
        // cout << endl;
    }

    cout << endl;
    vector<int> z;
    z = bottomview(root);
    for (int e = 0; e < z.size(); e++)
    {
        cout << z[e] << "  ";
    }

    //  Left view of tree

    cout << endl
         << endl
         << "Left View of tree" << endl;
    vector<int> aa;
    leftview(root, aa, 0);
    for (int i = 0; i < aa.size(); i++)
    {
        cout << aa[i] << "  ";
    }

    //  right view of tree

    cout << endl
         << endl
         << "Right View of tree" << endl;
    vector<int> bb;
    rightview(root, bb, 0);
    for (int i = 0; i < bb.size(); i++)
    {
        cout << bb[i] << "  ";
    }

    //    Height of tree
    int h = height(root);
    cout << "\n\nHeigth of tree is : ";
    cout << h;

    //  tree is same or not
    bool same = issame(root, root);
    if (same == 0)
        cout << endl
             << "Tree is not same";
    else
        cout << endl
             << "Tree is same";

    //  tree is balanced or not

    bool b = balancedtree(root);
    int b1 = balancedtree2(root);
    if (b1 == -1)
        cout << endl
             << "Not Balanced";
    else
        cout << endl
             << "Balanced tree";

    if (b == 0)
        cout << endl
             << "Not Balanced";
    else
        cout << endl
             << "Balanced tree";

    // diameter of tree

    int maxi = 0;
    int c = diameter(root);
    int l = diameter2(root, maxi);

    cout << endl
         << "Diameter of tree is " << maxi;
    cout << endl
         << "Diameter of tree is " << c;

    //  tree is symmetrical or not

    bool cc = issymmetrical(root->left, root->right);
    if (cc == true)
        cout << endl
             << "Tree is symmetrical";
    else
        cout << endl
             << "Tree is Unsymmetrical";

     vector<int> t;
     cout<<endl;
    //  getpathfromroot(root,t,4);
    //  for(int i=0;i<t.size();i++)
    //  {
    //     cout<<t[i]<<"->";
    //  }        

if (getpathfromroot(root, t, 7))
    {
        for (int i=0; i<t.size()-1; i++)   
            cout << t[i] << "->";
        cout << t[t.size() - 1];   
    }

    Node *tt=lowestCommonAncestor(root,t2,t3);
    cout<<endl<<"Lowest common ancestor is "<<tt->data;


    cout<<endl<<"Number of nodes  "<<countnode(root);
    return 0;
}