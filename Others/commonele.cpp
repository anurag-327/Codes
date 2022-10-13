#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[8]={1,2,3,4,5,6,8,9};
    int b[8]={4,5,6,8,9,10,11,13};
    int c[8]={6,8,6,10,11,12,13,15};
    int i,j,k;
    cout<<"\n Common Elements are : ";
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            for(k=0;k<8;k++)
            {
               if(a[i]==b[j]&&a[i]==c[k])
               {
                  cout<<a[i];
                }
            }    
            
        }
    }
    return 0;
}