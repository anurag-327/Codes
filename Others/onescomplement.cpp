#include<bits/stdc++.h>
using namespace std;
int binary(int a[],int n)
{
     int d,i=0;
    //  =0,b=10,base=1;
    while(n!=0)
    {
        d=n%2;
        a[i]=d;      
        n=n/2;
        i++;
    }
    int q=i;
    cout<<"\n Binary Rep of number is :: ";
    for(int j=q-1;j>=0;j--)
    {
    cout<<a[j];
    }
    return q;
}
int main()
{
    int a[10];
    int n;
    cout<<"\n Enter a decimal number";
    cin>>n;
    int q=binary(a,n);  //to create binary rep of number
    for(int i=0;i<q;i++)
    {
        if(a[i]==0)
        a[i]=1;
        else 
        a[i]=0;
    }

    cout<<"\n 1's Complement is :: ";
    for(int j=q-1;j>=0;j--)
    { 
    cout<<a[j];
    }

    return 0;
}