#include<iostream>
using namespace std;
int main()
{
    int i,j,k,t=1;
    for(i=5;i>=1;i--)
    {
        int m=1;
        for(j=1;j<=2*i-1;j++)
        {
          cout<<m;
          m++;
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