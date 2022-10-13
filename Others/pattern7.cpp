#include<iostream>
using namespace std;
int main()
{
    int i,j,k;
    for(i=1;i<=3;i++)
    {
        int m='A';
        for(j=2;j>=i;j--)
        {
            cout<<" ";
        }
        for(k=1;k<=i;k++)
        {
            cout<<char(m);
            m++;
        }
        cout<<endl;
    }
}