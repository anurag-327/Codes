#include<iostream>
using namespace std;
int main()
{
    int i,j,k,c=0,l=3;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=c;j++)
        {
          cout<<" ";
        }
        c=c+1;
          for(k=1;k<=l;k++)
          {
            cout<<"*";
          }
          l=l-1;
        cout<<endl;
    } 
    return 0;
}