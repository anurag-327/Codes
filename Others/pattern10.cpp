#include<iostream>
using namespace std;
int main()
{
    int i,j,k,t=1,v=6;
    for(i=5;i>=1;i--)
    {
        for(j=1;j<=2*i-1;j++)
        {
          cout<<"6";
        }
        cout<<endl;
        for(k=1;k<=t;k++)
        {
            cout<<"*";
        }
         for(k=v;k>=1;k--)
        {
            cout<<"*";
        }
        t=t+1;
        v=v-1;
    } 
    return 0;
}