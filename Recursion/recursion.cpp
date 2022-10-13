#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
   if(n==0)
   return 1;

   return n*factorial(n-1);
}
int powerof2(int n)
{
    if(n==1)
    return 2;

    return 2*powerof2(n-1);
}
int apowerb(int a,int b)
{
    if(b==1)
    return a;
    int ans=apowerb(a,b/2);
    if(b%2==0)
    return ans*ans;
    else
    return a*ans*ans;
}
void onetoN(int n)
{
    if(n==0)
    return;

    onetoN(n-1);
    cout<<n<<" ";
}
void Ntoone(int n)
{
    if(n==0)
    return;

    cout<<n<<" ";
    onetoN(n-1);
}
int fibonacci(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;

    int first=fibonacci(n-1);
    int second=fibonacci(n-2);

    return (first+second);
}
int nthstair(int n)
{
    if(n<0)
    return 0;
    if(n==0)
    return 1;

    return nthstair(n-1)+nthstair(n-2);
}
bool issorted(int arr[],int size)
{
    if(size==0||size==1)
    return true;
    if(arr[1]<arr[0])
    return false;
    
    else
    return(issorted(arr+1,size-1));

}
int sumofarray(int arr[],int n)
{
    if(n==0)
    return 0;
    int sum=arr[0];
    return arr[0]+sumofarray(arr+1,n-1);
    // return sum;
}
bool linearsearch(int arr[],int n,int key)
{
    if(n==0)
    return false;
    if(arr[0]==key)
    return true;
    return linearsearch(arr+1,n-1,key);
}
bool binarysearch(int arr[],int start,int end,int key)
{
    if(start>=end)
    return false;
    int mid=start+(end-start)/2;
    if(arr[mid]==key)
    return true;
    else if(arr[mid]>key)
    return binarysearch(arr,start,mid-1,key);
    else
    return binarysearch(arr,mid+1,end,key);

}
int firstoccurence(int arr[],int start,int end,int key)
{
    if(start>end)
    return -1;

    int mid=start+(end-start)/2;
    int ans=-1;
    if(arr[mid]==key)
    {
        ans=mid;
        int t=firstoccurence(arr,start,mid-1,key);
        if(t!=-1)
        ans=t;
    }
    else if(arr[mid]>key)
    ans=firstoccurence(arr,start,mid-1,key);
    else
    ans=firstoccurence(arr,mid+1,end,key);

    return ans;
}
int lastoccurence(int arr[],int start,int end,int key)
{
    if(start>end)
    return -1;
    
    int mid=start+(end-start)/2;
    int ans=-1;
    if(arr[mid]==key)
    {
        ans=mid;
        int t=lastoccurence(arr,mid+1,end,key);
        if(t!=-1)
        ans=t;
    }
    else if(arr[mid]>key)
    ans=lastoccurence(arr,start,mid-1,key);
    else
    ans=lastoccurence(arr,mid+1,end,key);

    return ans;
}
int pivotpoint(int arr[],int start,int end)
{
    if(start>end)
    return -1;

    int mid=start+(end-start)/2;
    if(arr[mid]<arr[mid-1])
    {
        return arr[mid];
    }
    else if(arr[mid]>arr[0])
    return pivotpoint(arr,mid+1,end);
    else
    return pivotpoint(arr,start,mid);
}
void reversestring(string &s,int i)
{
    if(i>s.length()/2)
    return ;
    swap(s[i],s[s.size()-i-1]);

    reversestring(s,i+1);
}
bool ispalindrome(string s,int i)
{
    if(i>=s.length()/2)
    return true;

    if(s[i]!=s[s.size()-i-1])
    return false;
    
    return ispalindrome(s,i+1);

}
void subsets(vector<int> input,vector<int> &output,int n,vector<vector<int>> &ans)
{
    if(n>=input.size())
    {
    ans.push_back(output);
    return ;
    }
    //  Include element
    output.push_back(input[n]);
    subsets(input,output,n+1,ans);
    output.pop_back();
    // exclude element
    subsets(input,output,n+1,ans);  
}
void stringsubsets(string s,string &output,int n,vector<string> &ans)
{
    if(n>=s.size())
    {
        if(output.length()>0)
           ans.push_back(output);
    return ;
    }
    //  Include element
    output.push_back(s[n]);
    stringsubsets(s,output,n+1,ans);
    output.pop_back();
    // exclude element
    stringsubsets(s,output,n+1,ans);  
}
int main()
{
    int n;
    cout<<"Enter a Number ::";
    cin>>n;
    cout<<"Factorial of a Number ::"<<factorial(n)<<endl;
    cout<<"Power of 2 ::"<<powerof2(n)<<endl;
    cout<<"a power of b ::"<<apowerb(3,4)<<endl;
    onetoN(10);
    cout<<endl;
    Ntoone(10);
    cout<<endl;
    cout<<fibonacci(5);
    cout<<endl<<nthstair(5);
    int arr[5]={1,2,2,2,5};
    cout<<endl<<issorted(arr,5);
    cout<<endl<<"sum of array is: "<<sumofarray(arr,5);
    cout<<endl<<linearsearch(arr,5,13);
    cout<<endl<<binarysearch(arr,0,5,9);
    cout<<endl<<firstoccurence(arr,0,5,2);
    cout<<endl<<lastoccurence(arr,0,5,2);
    cout<<endl<<"Count of no of element:"<<lastoccurence(arr,0,5,2)-firstoccurence(arr,0,5,2)+1;
    int b[6]={4,5,6,7,2,3};
    cout<<endl<<pivotpoint(b,0,5);
    string s="hello";
    reversestring(s,0);
    cout<<endl<<s;
    string p="OYe";
    cout<<endl<<ispalindrome(p,0)<<endl;

    vector<int> input={1,2,3};
    vector<int> output;
    vector<vector<int>> ans;
    subsets(input,output,0,ans);
    string r="";
    vector<string> ans1;
    stringsubsets(p,r,0,ans1);
    for(auto it:ans)
    {
        for(auto it1:it)
        {
            cout<<it1<<" ";
        }
        cout<<endl;
    }

    for(auto it:ans1)
    {
        cout<<it<<endl;
    }
}

