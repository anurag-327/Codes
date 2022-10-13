#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *create(int data)
{
    node *p=new node;
    p->data=data;
    p->next=NULL;
}
void middlell(node *head)
{
    node *slow=head;
    node *fast=head;
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"\n Middle element="<<slow->data;
}
void display(node *p)
{
    while(p!=NULL)
    {
        cout<<"\n Data is  :: ";
        cout<<p->data;
        p=p->next;
    }
}
int main()
{
    node *head=create(3);
    node *p1=create(6);
    node *p2=create(3);
    node *p3=create(8);
    node *p4=create(55);
    node *p5=create(6);
    head->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=p4;
    p4->next=p5;
    display(head);
    middlell(head);
    return 0;
}