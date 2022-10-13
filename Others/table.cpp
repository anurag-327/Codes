#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cout<<"\nEnter no whose table you want to print: ";
    cin>>n;
    cout<<"\n Table of "<<n<<" is :";
    for(i=1;i<=10;i++)
    {
        cout<<endl<<n<<" * "<<i<<" = "<<n*i;
    }
    return 0;
}