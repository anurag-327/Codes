#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c[]="Anurag Srivastav";
    int len,i,j;
    len=0;
    for(i=0;c[i]!='\0';i++)
    {
       len=len+1;
    }
    i=0;
    j=len-1;
    char temp;
    while(i<j)
    {
       temp=c[j];
       c[j]=c[i];
       c[i]=temp;
       i++;
       j--;
    }
    cout<<"\n Reversed string ::"<<c;
    return 0;
}