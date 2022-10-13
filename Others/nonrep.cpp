#include<bits/stdc++.h>
using namespace std;
int nonrep(int a[],int n)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(j==7)
            {
                return a[i];
            }
           if(i!=j&&a[i]==a[j])
           {
               break;
           }
          
        }
    }
    return -1;
}
int main()
{
    int arr[8]={1,4,2,5,7,2,4,8};
    // int f=firstrep(arr,8);
    cout<<"\n first  non repeating element : "<<nonrep(arr,8);
}