#include<bits/stdc++.h>
using namespace std;
void sort012s(int arr[],int n)
{
    int count0,count1,count2;
    int i;
    count0=count1=count2=0;
    for(int i=0;i<5;i++)
    {
       
        if(arr[i]==0)
        count0+=1;
        if(arr[i]==1)
        count1+=1;
        if(arr[i]==2)
        count2+=1;
    } 
    for(i=0;i<count0;i++)
    {
        arr[i]=0;
    }
    for(i=count0;i<count0+count1;i++)
    {
        arr[i]=1;
    }
    for(i=count0+count1;i<count0+count1+count2;i++)
    {
        arr[i]=2;
    }
}
int main()
{
    int arr[5]={1,0,2,2,0};
    cout<<"\n Sorted array is:";
    sort012s(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i];
    }
    return 0;
}