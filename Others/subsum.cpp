#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[8]={1,4,2,5,7,2,4,8};
    int i,j,sum,key=14;
    for(int i=0;i<8;i++)
    {
        sum=0;
        for(j=i;j<8;j++)
        {
           sum=sum+arr[j];
           if(sum==key)
           {
           cout<<"\n position is:"<<i+1<<" "<<j+1;
           }
        }
    }
    cout<<"\n hiii";
    return 0;
}