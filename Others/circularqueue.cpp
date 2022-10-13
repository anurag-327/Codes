#include<bits/stdc++.h>
using namespace std;
struct que
{
    int front;
    int rear;
    int size;
    int *arr;
};



void delque(que *s)
{
    int val;
    if(s->rear==s->front)
    {
        cout<<"\n  Queue Empty";
    }
    else
    {
        s->front=(s->front+1)%s->size;
        val=s->arr[s->front];
        cout<<"\n Element is::"<<val;
    }
}
// void display(que *s)
// {
    // int val;
    // if(isEmpty(s))
    // {
        // cout<<"\n  Queue Empty";
    // }
    // else
    // {
    //    int st=s->front;
    //    st++;
    //    for(;st/<=s->rear;st++)
    //    {
        //    cout<<"\n DATA IS :::"<<s->arr[st]<<endl;
    //    }
    // }
// }
void enque(que *s,int val)
{
    if((s->rear+1)%s->size==s->front)
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
    que s;
    s.size=10;
    s.front=s.rear=-1;
    s.arr=new int[s.size*sizeof(int)];
 
     enque(&s,45);
     enque(&s,56);
     enque(&s,32);
    //  display(&s);
     delque(&s);
     delque(&s);
     delque(&s);

    
}