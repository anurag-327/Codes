#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[8]={-1,2,4,-2,-4,4,5,-2};
    int i,j=0,temp;
    for(i=0;i<8;i++)
    {
        if(arr[i]<0)
        {
            if(i!=j)
            {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            }
            j++;
        }
    }
    for(i=0;i<8;i++)
    {
        cout<<arr[i];
    }
    return 0;
}