#include<bits/stdc++.h>
using namespace std;
void subtree(vector<int>v,int arr[],int index,int n)
{
    if(index==n)
    {
        cout<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<",";
        }
        return;
    }
    v.push_back(arr[index]);
    subtree(v,arr,index+1,n);
    v.pop_back();
    subtree(v,arr,index+1,n);
}

void sumseq(vector<int>v1,int arr[],int index,int n,int sum,int k)
{
    // cout<<"jui";
    if(index==n)
    {
       if(sum==k)
       {
        cout<<endl;
        for(int i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<",";
        }
        cout<<"sum="<<sum;
        // m++;
    } 
        return;
    }
    v1.push_back(arr[index]);
    sum=sum+arr[index];
    sumseq(v1,arr,index+1,n,sum,k);
    v1.pop_back();
    sum=sum-arr[index];
    sumseq(v1,arr,index+1,n,sum,k);
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int n=5;
    int i=0,j=0,sum=0;
    vector<int>v;
    vector<int>v1;
    subtree(v,arr,i,n);
    sumseq(v1,arr,j,n,sum,6);
    return 0;
}