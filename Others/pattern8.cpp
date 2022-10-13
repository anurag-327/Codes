#include<bits/stdc++.h>
using namespace std;
// hollow rectangle
int main()
{
    int i,j,k;
    for(i=1;i<=5;i++)
    {
        if((i==1)||(i==5))
        {
            for(j=1;j<=8;j++)
            {
                cout<<"*";
            }
        }
        else
        {
            cout<<"*";
            for(k=1;k<=6;k++)
            {
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
   }
   return 0;
}   