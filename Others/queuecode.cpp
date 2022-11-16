#include<bits/stdc++.h>
using namespace std;
struct que
{
    int front;
    int rear;
    int size;
    int *arr;
};
int isFull(que *q)
{
    if(q->rear==q->size-1)
    {
        return(1);
    }
    else
    {
        return 0;
    }
}
int isEmpty(que *q)
{
    if(q->rear==q->front && q->rear==-1)
    {
        return(1);
    }
    else
    {
        return 0;
    }
}


void delque(que *s)
{
    int val;
    if(isEmpty(s))
    {
        cout<<"\n  Queue Empty";
    }
    else
    {
        s->front++;
        val=s->arr[s->front];
        cout<<"\n Element is::"<<val;
    }
}
void display(que *s)
{
    int val;
    if(isEmpty(s))
    {
        cout<<"\n  Queue Empty";
    }
    else
    {
       int st=s->front;
       st++;
       for(;st<=s->rear;st++)
       {
           cout<<"\n DATA IS :::"<<s->arr[st]<<endl;
       }
    }
}
void enque(que *s,int val)
{
    if(isFull(s))
    {
        cout<<"\n  Queue Empty";
    }
    else
    {
        s->rear++;
        s->arr[s->rear]=val;
        cout<<"\n Element inserted:";
    }
}
int main()
{
    que *s=new que;
    s->size=10;
    s->front=s->rear=-1;
    s->arr=new int[s->size*sizeof(int)];
 
     delque(s);
     enque(s,45);
     enque(s,56);
     enque(s,32);
    //  display(&s);
     delque(s);
     delque(s);

    
}
