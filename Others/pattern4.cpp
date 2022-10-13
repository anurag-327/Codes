#include<iostream>
using namespace std;
int main()
{
    int i,j,k,t=1;
    for(i=3;i>=1;i--)
    {
        for(j=1;j<=2*i-1;j++)
        {
          cout<<"*";
        }
        cout<<endl;
        for(k=1;k<=t;k++)
        {
            cout<<" ";
        }
        t=t+1;
    } 
    return 0;
}