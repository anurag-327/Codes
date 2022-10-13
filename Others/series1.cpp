#include<iostream>
#include<math.h>
using namespace std;
int main()
{
     int i,j,f,x,k=0,p=0;
     float s;
     cout<<" Enter value of x  ::";
     cin>>x;
     for(i=2;i<=5;i++)
     {
         f=1;
         for(j=1;j<=i;j++)
         {
         f=f*i;
         }
         p=pow(x,i);
         k=p/f;
         if(i%2==0)
         s=s+k;
         else
         s=s-k;

     }
     s=s-1;
     cout<<"\n Sum of series :"<<s;
     return 0;
}






