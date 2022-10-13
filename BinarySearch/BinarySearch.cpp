#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[],int n,int key)
{
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            return true;
        }
        else if(arr[mid]>key)
        end=mid-1;
        else
        start=mid+1;
    }
    return false;
}
bool recursivebinarysearch(int arr[],int start,int end,int key)
{
    if(start>=end)
    return false;
    int mid=start+(end-start)/2;
    if(arr[mid]==key)
    return true;
    else if(arr[mid]>key)
    return recursivebinarysearch(arr,start,mid-1,key);
    else
    return recursivebinarysearch(arr,mid+1,end,key);

}
bool recursivebinarysearchdecending(int arr[],int start,int end,int key)
{
    if(start>=end)
    return false;
    int mid=start+(end-start)/2;
    if(arr[mid]==key)
    return true;
    else if(arr[mid]<key)
    return recursivebinarysearch(arr,start,mid-1,key);
    else
    return recursivebinarysearch(arr,mid+1,end,key);

}
int firstoccurence(int arr[],int n,int key)
{
    int start=0,end=n-1,mid=0,ans=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]>key)
        end=mid-1;
        else
        start=mid+1;
    }
    return ans;
}
int lastoccurence(int arr[],int n,int key)
{
    int start=0,end=n-1,mid=0,ans=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]>key)
        end=mid-1;
        else
        start=mid+1;
    }
    return ans;
}
int recursivefirstoccurence(int arr[],int start,int end,int key)
{
    if(start>end)
    return -1;

    int mid=start+(end-start)/2;
    int ans=-1;
    if(arr[mid]==key)
    {
        ans=mid;
        int t=recursivefirstoccurence(arr,start,mid-1,key);
        if(t!=-1)
        ans=t;
    }
    else if(arr[mid]>key)
    ans=recursivefirstoccurence(arr,start,mid-1,key);
    else
    ans=recursivefirstoccurence(arr,mid+1,end,key);

    return ans;
}
int recursivelastoccurence(int arr[],int start,int end,int key)
{
    if(start>end)
    return -1;
    
    int mid=start+(end-start)/2;
    int ans=-1;
    if(arr[mid]==key)
    {
        ans=mid;
        int t=recursivelastoccurence(arr,mid+1,end,key);
        if(t!=-1)
        ans=t;
    }
    else if(arr[mid]>key)
    ans=recursivelastoccurence(arr,start,mid-1,key);
    else
    ans=recursivelastoccurence(arr,mid+1,end,key);

    return ans;
}
void countofelements(int arr[],int n,int key)
{
    int fo=firstoccurence(arr,n,key);
    int lo=lastoccurence(arr,n,key);
    cout<<lo-fo+1;
    int forecur=recursivefirstoccurence(arr,0,n-1,key);
    int lorecur=recursivelastoccurence(arr,0,n-1,key);
    cout<<lorecur-forecur+1;
}

int pivotofarray(int arr[],int n)
{
    
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]<arr[mid-1])
        {
            return arr[mid];
        }
        else if(arr[mid]>arr[0])
        start=mid+1;
        else
        end=mid-1;
    }
    return -1;
}
int recursivepivotofarray(int arr[],int start,int end)
{
    if(start>end)
    return -1;

    int mid=start+(end-start)/2;
    if(arr[mid]<arr[mid-1])
    {
        return arr[mid];
    }
    else if(arr[mid]>arr[0])
    return recursivepivotofarray(arr,mid+1,end);
    else
    return recursivepivotofarray(arr,start,mid);
}

int searchinrotatedarray(int nums[], int start, int end, int target)
{
    int mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[start]<=nums[mid])
        {
            if(target>=nums[start]&&target<=nums[mid])
                end=mid-1;
            else
                start=mid+1;
                                                   
        }
        else
        {
            if (nums[mid] <= target && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;                            
        }
    }
    return -1;
}

int squareroot(int x)
{
    int start=1,end=x,ans=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        int msq=mid*mid;
        if(msq==x)
        return mid;
        else if(msq>x)
        end=mid-1;
        else
        {
            start=mid+1;
            ans=mid;
        }
    }
    return ans;
}
int peakelement(int arr[],int n)
{
   int start=0,end=n-1,mid=0;
   while(start<=end)
   {
    mid=start+(end-start)/2;
    if(mid>0 && mid<n-1)
    {
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
        {
            return mid;
        }
        else if(arr[mid-1]>arr[mid])
        end=mid-1;
        else
        start=mid+1;
    }
    else if(mid==0)
    {
        if(arr[0]>arr[1])
        return 0;
        else
        return 1;
    }
    else if(mid==n-1)
    {
        if(arr[n-1]>arr[n-2])
        {
            return n-1;
        }
        else
        {
            return n-2;
        }
    }
   } 
   return -1;
}
int bitonicpeak(int arr[],int n)
{
    return peakelement(arr,n);
}
int searchinbitonicarray(int arr[],int n,int k)
{
    int index=bitonicpeak(arr,n);
    cout<<index;
    bool a=recursivebinarysearch(arr,0,index-1,k);
    
    bool b=recursivebinarysearchdecending(arr,index,n-1,k);
    return b;
    // if(a==false&&b==true)
    // return b;
    // else if(b==false&&a==true)
    // return a;
    // else 
    // return-1;
    // return -1;

}
int main()
{
    int arr[4]={5,30,20,15};
    int arr2[6]={1,3,8,12,4,2};
    int arr3[6]={15,12,6,4,3,2};
    // cout<<peakelement(arr,4);
    // cout<<endl<<bitonicpeak(arr2,6);
    // cout<<endl<<searchinbitonicarray(arr2,6,8);
    cout<<endl<<recursivebinarysearchdecending(arr3,0,5,4);
}