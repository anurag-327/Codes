#include<iostream>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i,j,k;
    for(i=1;i<=3;i++)
    {
        int m=1;
        for(j=2;j>=i;j--)
        {
            cout<<" ";
        }
        for(k=1;k<=i;k++)
        {
            cout<<m;
            m=m+1;
        }
        cout<<endl;
    }
}