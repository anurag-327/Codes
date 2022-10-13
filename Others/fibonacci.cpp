#include<iostream>
using namespace std;
int main()
{
    cout<<"hello Guys";
    int first=0,second=1,third=0;
    cout<<first<<","<<second<<",";
    while(third<=500)
    {
        third=first+second;
        first=second;
        second=third;
        cout<<third<<",";
    }
    return 0;
}
