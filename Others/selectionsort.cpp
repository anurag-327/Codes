#include<bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int n)
{
    int temp=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    // if(isorted)
    // cout<<"\n  *******  Already Sorted  *******";
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
    bubblesort(arr,10);
    cout<<"\n  *****  sorted array  ****";
    display(arr,10);
    return 0;
}