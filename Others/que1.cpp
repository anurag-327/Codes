#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,Z,Y,A,B,C,i;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>Z>>Y>>A>>B>>C;
        if(Z-Y >=A+B+C)
        {cout<<"\nYES";}
        else
        {cout<<"\nNO";}
    }
    return 0;
}