#include<iostream>
// #include<conio.h>
using namespace std;
int main()
{
    int n,i=2,a=0;
    cout<<"\n Enter number to find number is prime no or not";
    cin>>n;
    while(n%i==0)
    {
        i++;
        a=1;
        break;
    }
    if(a==0)
    cout<<"\n No is prime no";
    else
    cout<<"\n No is not primenumber";
    // getch();
    return 0;

}