#include<bits/stdc++.h>
using namespace std;
int freq(int a[],int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        count+=1;
    }
    return count;
}
int main()
{
    int arr[10]={2,3,4,4,5,4,2,2,4,6};
    cout<<"\n Frequency of element [9] is: "<<freq(arr,10,9);
    return 0;
}