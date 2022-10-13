#include<bits/stdc++.h>
using namespace std;
void subarr(int a[],int n)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=i;j<8;j++)
        {
           if((i!=j)&&((a[i]==1||a[i]==0)||(a[j]==0||a[j]==1)))
           {
               cout<<"\n Sub Array : "<<a[i]<<" "<<a[j];
           }
          
        }
    }
}
int main()
{
    int arr[8]={1,4,0,5,7,2,4,8};
    // int f=firstrep(arr,8);
    subarr(arr,8);
    return 0;
}