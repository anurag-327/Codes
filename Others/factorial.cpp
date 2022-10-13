#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,f=1;
    cout<<"\n Enter number whose factorial you want to calculate :";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    cout<<"\n Factorial of number is ::"<<f;
    return 0;
}