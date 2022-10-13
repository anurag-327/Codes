#include<iostream>
using namespace std;
int main()
{
     int n;
     int digit,rem=0,n1;
     cout<<"Enter No to check palindrome and reverse of the number";
     cin>>n;
     n1=n;
     while(n>0)
     {
         digit=n%10;
         rem=rem*10+digit;
         n=n/10;
     }
     if(n1==rem)
     {
     cout<<" \n Number is palindrome ";
     }
     else
     {
     cout<<"\nNumber is not palindrome";
     }

    cout<<" \n REVERSE OF THE NUMBER IS:: "<<rem;
    return 0;
}