#include<iostream>
using namespace std;
int main()
{
    int i,j,k=0;
    for(i=1;i<=5;i++)
    {
        for(j=5;j>=i;j--)
        {
          cout<<"*";
        }
        cout<<endl;
    } 
    return 0;
}