#include<iostream>
using namespace std;
int main()
{
    int i,j,k,l=0;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=5-i;j++)
        {
            cout<<" ";
        }
        cout<<"*";
        for(k=1;k<=2*l-1;k++)
          {
            cout<<" ";
          }
          l=l+1;
          if(i>1)
          cout<<"*";
        cout<<endl;
    }
    for(int m=1;m<=9;m++)
    {
    cout<<"*";
    }
    return 0;
}