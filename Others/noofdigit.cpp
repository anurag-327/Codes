#include<bits/stdc++.h>
using namespace std;
int main()
{
    int d,r=0;
    int n;
    cout<<"\n Enter the number :";
    cin>>n;
    while(n!=0)
    {
        d=n%10;
        r=r+1;
        n=n/10;
    }
    cout<<"\n No of digit in the number is :"<<r;
    return 0;
}