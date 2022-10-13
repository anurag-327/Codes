#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[8]={1,3,2,5,7,0,6,4};
    int i,j,sum=7,no=0;
    for(i=0;i<8;i++)
    {
        for(j=i+1;j<8;j++)
        {
            if(i!=j)
            {
                if(a[i]+a[j]==sum)
                {
                cout<<"\n pair is : "<<i+1<<" and "<<j+1;
                no=no+1;
                }
            }
        }
    }
    cout<<"\n no of pairs : "<<no/2;
    return 0;
}