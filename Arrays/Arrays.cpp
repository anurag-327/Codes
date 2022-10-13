#include<bits/stdc++.h>
using namespace std;

int largest(int arr[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
int smallest(int arr[],int n)
{
   int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        min=arr[i];
    }
    return min;
}
bool issorted(int arr[],int n)
{
   int i=0;
   while(i<n)
   {
    if(arr[i]>arr[i+1])
    return false;
    i++;
   }
   return true;
}
void reversearray(int arr[],int n)
{
   int i=0;
   while(i<n/2)
   {
    swap(arr[i],arr[n-i-1]);
    i++;
   }
}
void move0toend(int arr[],int n)
{
   int temp=0;
   for(int i=0;i<n;i++)
   {
    if(arr[i]!=0)
    {
        swap(arr[i],arr[temp]);
        temp++;
    }
   }
}
void removeduplicates(int arr[],int n)
{
    int temp=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[temp-1])
        {
            swap(arr[i],arr[temp]);
            temp++;
        }
    }
}
void lrotatebyone(int arr[],int n)
{
    int temp=arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
void reverse(int arr[],int i,int j)
{
    while(i!=j)
   {
    swap(arr[i],arr[j]);
    i++; 
    j--;
   }
}
void lrotatebyD(int arr[],int n,int d)
{
    // method 1-left rotate by d timec
    // for(int i=1;i<d;i++)
    // {
    //     lrotatebyone(arr, n);
    // }

    // method 2- use a temp array

    // method 3-reverse 0-(d-1) then reverse d-n then reverse 0-n 
    // ex-{1,2,3,4,5} rotate by d timespec
    // rev 1-{2,1,3,4,5}
    // rev 2-{2,1,5,4,3}
    // rev-3{3,4,5,1,2}

    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
} 
void leaderinarray(int arr[],int n)
{
    // an element is a leader if it does have any larger value on right hand side 
    // Method 1- O[n^2] app 
    // i=0->n, j-i+1->n [if arr[i]<arr[j] for all case it is leader ]

    // Method 2- start from right side and keep a record of max value
    int curleader=arr[n-2];
    cout<<curleader;
    for(int i=n-2;i>=0;i--)
    {
         if(arr[i]>curleader)
         curleader=arr[i];
         cout<<curleader<<" ";
    }

    // Method 3- use stack like next greater element 

} 
void frequencyofelementinsortedarray(int arr[],int n)
{
    // Method 1-> Map method 
    map<int ,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto it:m)
    {
        cout<<it.first<<" "<<it.second;
    }

    // Method 2 Since it is a sorted array if arr[i]==arr[i-1] inc count print it or store in vector<pair>
    // int count=0;
    // for(int i=1;i<n;i++)
    // {
    //     if(arr[i]==arr[i-1])
    //     {
    //         count++;
    //     }
    //     else
    //     count=0;
    //     cout<<arr[i]<<count;
    // }
}

int maxconsecutive1s(int arr[],int n)
{
    // Method 1- basic approach with 2 loops. find max of all counts 
    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     int count=0;
    //     for(int j=i;j<n;j++)
    //     {
    //         if(arr[j]==1)
    //         count++;
    //         else
    //         break;
    //     }
    //     ans=max(ans,count);
    // }
    // return ans;

    // method 2 keep inc count as you get 1 and as soon as you get 0 make count =0 and take max of count 

    int ans1=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
        count++;
        ans1=max(ans1,count);
        }
        else
        count=0;
    }
    return ans1;
}
int maxsumsubarray(int arr[],int n)
{

    // KADANE'S ALGORITHM 
    int sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        ans=max(ans,sum);
        if(sum<0)
        sum=0;
    }
    return ans;
} 
int rainwatertrapping(int arr[],int n)
{
    int sum=0;
    int lmax[n],rmax[n];
    lmax[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        lmax[i]=max(lmax[i-1],arr[i]);
    }
    rmax[n-2]=arr[n-2];
    for(int i=n-2;i>=0;i--)
    {
        rmax[i]=max(rmax[i+1],arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        sum+=max(lmax[i],rmax[i]-arr[i]);
    }
    return sum;
}
int majorityelement(int arr[],int n)
{
    // majority element is one which occurs more then n/2 times in an array 
    // Method 1 -> using map ans storing frequency of all elements 

    map<int ,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto it:m)
    {
        if(it.second>n/2)
        cout<<endl<<it.first<<" is a majority element"<<endl;
    }
}
int repeatingelement(int arr[],int n)
{
    // nos from 0-n and and any one no occurs multiple times 
    // Method 1-> using two loops
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]==arr[i])
            {
                cout<<"Repeating element is"<<arr[i];
                break;
            }
        }
    }
    // Method 2-> keep record of visited elements in a visited[n-1] array 
    int vis[n-1]={false};
    for(int i=0;i<n;i++)
    {
        if(vis[arr[i]]==true)  //means already vivited
            return arr[i];
        vis[arr[i]]=true; //mark elememt visited    
    }
    // Method 3-> sort the array ans check consecutive locations
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
        return arr[i];
    }
  
    // Method 4- Cycle detection algorithm of linkedlist
}
bool twosum(int arr[],int x,int i,int j)
{
    while(i<j)
    {
        if(arr[i]+arr[j]>x)
        j--;
        else if(arr[i]+arr[j]<x)
        i++;
        else
        return true;
    }
    return false;
}
bool threesum(int arr[],int n)
{
    for(int i=0;i<n-2;i++)
    {
        if(twosum(arr,-arr[i],i+1,n))
        return true;
    }
    return false;
}
int main()
{
    int arr[5]={2,5,3,7,44};
    cout<<largest(arr,5);
    cout<<endl<<smallest(arr,5);
    int b[8]={0,2,-3,-1,0,0,1,1};
    cout<<endl<<maxconsecutive1s(b,8);
    cout<<endl<<twosum(b,2,0,7);
    cout<<endl<<threesum(b,7);
   return 0;
}