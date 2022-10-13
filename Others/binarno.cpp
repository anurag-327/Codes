#include<iostream>
using namespace std;
int main()
{
    int d,i=0,rem=0,n,b=10,base=1;
    int a[10];
    cout<<"\n Enter a decimal number";
    cin>>n;
    while(n!=0)
    {
        d=n%2;
        a[i]=d;      
        n=n/2;
        i++;
    }
    int q=i;
    for(int j=q-1;j>=0;j--)
    {
    cout<<a[j];
    }
    return 0;

}