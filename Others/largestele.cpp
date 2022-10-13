#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,l=0;
    int a[3][3];
    cout<<" \n Enter elements of the 3*3 array :";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           cin>>a[i][j];
        }
    }
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           if(l<a[i][j])
           l=a[i][j];
        }
    }
    cout<<"\n Largest number is :"<<l;

return 0;
}