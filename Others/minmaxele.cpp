#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],n,max,min;
    cout<<"\n Enter size of the array ::";
    cin>>n;
    cout<<"\n Enter Elements of the array ::";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    max=min=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    cout<<"\n Max Element::"<<max;
    cout<<"\n Min Element::"<<min;
    return 0;
    
}