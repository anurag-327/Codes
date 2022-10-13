#include<bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int n)
{
    int temp=0,isorted=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                isorted=0;
            }
        }
    }
    if(isorted)
    cout<<"\n  *******  Already Sorted  *******";
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