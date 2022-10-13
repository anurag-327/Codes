#include<bits/stdc++.h>
using namespace std;
void altpos(int arr[],int n)
{
    int i,j,c=1;
    int b[8]={0,0,0,0,0,0,0,0};
    int k=0;
    for(i=0;i<8;i++)
    {
      if(c%2==0&&arr[i]>=0)
       {
               b[k]=arr[i];
               k++;
               c++;
       }
        if(c%2!=0&&arr[i]<0)
       {
               b[k]=arr[i];
               k++;
               c++;
       }
    }
    cout<<b[0]<<endl;
    for(int m=0;m<8;m++)
    {
        cout<<b[m]<<" ";
    }
}
int main()
{
    int arr[8]={-1,4,-2,-5,7,2,-4,8};
    altpos(arr,8);
    cout<<" HII";
    // cout<<"\n first  non repeating element : "<<nonrep(arr,8);
    return 0;
}