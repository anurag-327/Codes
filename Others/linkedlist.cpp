#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node *next;
};


node *insertatbeg(node *head,int k)
{
    node *p=new node;
    p->data=k;
    p->next=head;
    head=p;
    return head;
}

void insertatend(node *head,int k)
{
    node *p=new node;
    node *t=head;
    p->data=k;
    p->next=NULL;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=p;
}

void insertatindex(node *head,int pos,int k)
{
    node *p=new node;
    p->data=k;
    node *t=head;
    for(int i=1;i<pos;i++)
    {
        t=t->next;
    }
    p->next=t->next;
    t->next=p;
}

node *removeatbeg(node *head)
{
    node *p=head;
    // emp *t=head;
    head=p->next;
    p->next=NULL;
    delete p;
    return head;
}

node *removeatend(node *head)
{
    node *p=head;
    node *q=head->next;
    // p->data=k;
    // p->next=NULL;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
    return head;
}

node *removeatindex(node *head,int pos)
{       
    node *p;
    // p->data=k;
    node *t=head;
    for(int l=0;l<pos-1;l++)
    {
        t=t->next;
    }
    p=t->next;
    t=p->next;
    p->next=NULL;
    delete(p);
    return head;
} 

void display(node *p)
{
    // cout<<endl;
    while(p!=NULL)
    {
        // cout<<"\n Data is  :: ";
        cout<<p->data<<"->";
        p=p->next;
    }
}

int count(node *head)
{
    node *current=head;
    int count=0;
    while(current!=NULL)
    {
        current=current->next;
        count++;
    }
    return(count);
}

/*node *getnodeat(node *head,int index)
{
    node *p=head;
    for(int i=1;i<index;i++)
    {
        p=p->next;
    }
    return(p);
}
 
int intersectionof2ll(node *l1,node *l2)
{
    node *t1=l1;
    node *t2=l2;
    int a=count(l1);
    int b=count(l2);
    int delta=abs(a-b);
    if(a>b)
    {
        for(int i=0;i,delta;i++)
        {
            t1=t1->next;
        }
    }
    else
    {
        for(int i=0;i,delta;i++)
        {
            t2=t2->next;
        }

    }
    while(t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;
    }
    return(t1->data);
}

void reversellbyswapping(node *head)
{
    int l1=0;
    int l2=count(head);
    while(l1<l2)
    {
    node *left=getnodeat(head,l1);
    node *right=getnodeat(head,l2);
    int temp=left->data;
    left->data=right->data;
    right->data=temp;
    l1++;
    l2--;
    }
}

void reversebyiteration(node *head)
{
    node *prev=NULL;
    node *curr=head;
    while(current!=NULL)
    {
        node *next=currnt->next;
        current->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

node *nthnodefromend(node *head,int n)
{
    node *fastptr=head,*slowptr=head;
    for(i=1;i<=n;i++)
    {
        fastptr=fastptr->next;
    }
    while(fastptr!=NULL)
    {
        fastptr=fastptr->next;
        slowptr=slowptr->next;
    }
    return(slowptr);
}

node *middleofll(node *head)
{
    node *fastptr=head,*slowptr=head;
    while(fastptr!=NULL)
    {
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    }
    return (slowptr);
}

void merge2sortedll(node *l1,node *l2)
{
    node *one=l1;
    node *two=l2;
    node *head2=NULL;
    while(one!=NULL&&two!=NULL)
    {
        if(one->data<two->data0)
        {
            removeatbeg(l1);
            insertatlast(head2,one->data);
            one=one->next;
        }
        if(two->data<one->data0)
        {
            removeatbeg(l2);
            insertatlast(head2,two->data);
            two=two->next;
        }
    }
    while(one!=NULL)
    {
        removeatbeg(l1);
        insertatlast(head2,one->data);
        one=one->next;
    }
    while(two!=NULL)
    {
        removeatbeg(l2);
        insertatlast(head2,two->data);
        two=two->next;
    }
}*/

void removedupll(node *head)
{
    node *curr=head;
    node *next_next;
    if(curr==NULL)
    return ;

    while(curr->next!=NULL)
    {
        if(curr->data=curr->next->data)
        {
            next_next=curr->next->next;
            free(curr->next);    
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    node *head=new node;
    node *second=new node;
    node *third=new node;
    node *tail=new node;
    head->data=56;
    second->data=57;
    third->data=57;
    tail->data=58;
    head->next=second;
    second->next=third;
    third->next=tail;
    tail->next=NULL;

    cout<<"\nsize :"<<count(head)<<endl;
    display(head);
    head=insertatbeg(head,45);
    cout<<"\nsize :"<<count(head)<<endl;
    display(head);
    insertatindex(head,3,57);
    cout<<"\nsize :"<<count(head)<<endl;
    display(head);
    insertatend(head,60);
    cout<<"\nsize :"<<count(head)<<endl;
    display(head);
    
     head=removeatbeg(head);
    cout<<"\nsize :"<<count(head)<<endl;
    display(head);
   
    // head=removeatindex(head,3);
    // cout<<"\nsize :"<<count(head)<<endl;
    // display(head);
   
    head=removeatend(head);
    cout<<"\nsize :"<<count(head)<<endl;
    display(head);
   
    removedupll(head);
    cout<<endl;
    display(head);
    // cout<<"\n     ***** now insertion";
    // head=insert(head);
    // cout<<"\n *****NEW DISPLAY";
    // display(head);
    // cout<<"\n ******* now deletion";
    // head=delette (head);
    // cout<<"\n *****NEW DISPLAY";
    // display(head);
    return 0;

}