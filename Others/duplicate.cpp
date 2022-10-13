#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[8]={2,3,4,2,5,5,6,3};
    int i,j;
      for(i=0;i<8;i++)
    {
        for(j=i+1;j<8;j++)
        {
            if(i!=j)
            {
                if(a[i]==a[j])
                {
                cout<<a[i]<<"  is repeating \n";
                }
            }
        }
    }
    return 0;
}