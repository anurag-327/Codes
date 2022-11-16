#include<bits/stdc++.h>
using namespace std;
struct stacks
{
    int size;
    int top;
    int *arr;
};
int isEmpty(stacks *ptr)
{
    if(ptr->top==-1)
    {
        return(-1);
    }
    else
    {
        return(0);
    }
}
int isFull(stacks *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return(-1);
    }
    else
    {
        return(0);
     }
}
void push(stacks* ptr,int val)
{
    if(isFull(ptr))
    {
        cout<<"\n stack overflow";
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
        cout<<"\n data pushed";
    }
}
int pop(stacks* ptr)
{
    int val;
    if(isEmpty(ptr))
    {
        cout<<"\n stack underflow";
        return(0);
    }
    else
    {
        cout<<2;
      val=ptr->arr[ptr->top];

      ptr->top--; 
      return(val);
    }
}

int main()
{
    stacks *s=new stacks;
    s->size=100;
    s->top=-1;
    s->arr=new int[(s->size)*(sizeof(int))];


    push(s,28);
    push(s,56);
    push(s,44);
    push(s,67);
    push(s,99);
    cout<<endl<<pop(s);
    // cout<<2;
    cout<<endl<<pop(s);
    // cout<<"hi"<<endl;
    return(0);
}
