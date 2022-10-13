#include<bits/stdc++.h>
using namespace std;
int peak(int arr[],int n)
{
    int i;
    if(n==1)
    return 0;
    if(arr[0]>arr[1])
    return 1;
    if(arr[n-1]>arr[n-2])
    return n;
    for(i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1]&&arr[i]>arr[i-1])
        return i+1;      
    }
    return 0;
}
int main()
{
    int arr[100],n,i;
    cout<<"\n Enter Size of the Array :";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m=peak(arr,n);
    cout<<"\n Peak element ::"<<m;
    return 0;

}