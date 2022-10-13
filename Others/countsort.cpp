#include<bits/stdc++.h>
using namespace std;
int maximum(int a[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    return(max);
}
void countsort(int a[],int n)
{
    int i;
    int max=maximum(a,n);
    int count[max];
    for(i=0;i<max;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
       count[a[i]]=count[a[i]]+1; 
    }
    i=0;
    int j=0;
    while(i<max+1)
    {
        if(count[i]>0)
        {
            a[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else
        {
            i++;
        }
    }   
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int arr[10]={55,65,23,99,12,66,33,49,11,9};
    cout<<"\n  ***  unsorted array  ***";
    display(arr,10);
    countsort(arr,10);
    cout<<"\n  *****  sorted array  ****";
    display(arr,10);
    return 0;
}