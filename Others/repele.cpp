#include<bits/stdc++.h>
using namespace std;
int firstrep(int a[],int n)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=i;j<8;j++)
        {
           if(i!=j)
           {
               if(a[i]==a[j])
               return a[i];
           }
          
        }
    }
    return -1;
}
int main()
{
    int arr[8]={1,4,2,5,7,2,4,8};
    // int f=firstrep(arr,8);
    cout<<"\n first repeating element : "<<firstrep(arr,8);
    return 0;
}