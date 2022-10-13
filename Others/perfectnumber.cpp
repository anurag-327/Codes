#include<iostream>
using namespace std;
int main()
{
    int sum=0,n,i=1;
    cout<<"\n Enter nio to check it is perfect no or not";
    cin>>n;
    while(i<=n/2)
    {
        if(n%i==0)
        {
        sum=sum+i;
        }
        i++;
    }
    if(sum==n)
    cout<<"\n Number is perfect no";
    else
    cout<<"\n Number is not a perfect no";
    return 0;
}