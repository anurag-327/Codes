#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[8]={1,2,3,4,5,6,8,9};
    int sum=0;
    for(int i=0;i<8;i++)
    {
        sum=sum+arr[i];
    }
    cout<<" MIssing element : "<<45-sum;
    return 0;
}