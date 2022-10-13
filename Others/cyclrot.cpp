#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[8]={1,2,3,4,5,6,7,8};
    int i,j,temp=arr[7];
    for(i=7;i>=0;i--)
    {
        arr[i]=arr[i-1];        
    }
    arr[0]=temp;
    cout<<"\n Rotated Array : ";
    for(i=0;i<8;i++)
    {
        cout<<arr[i];
    }
    return 0;
}