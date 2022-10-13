#include<bits/stdc++.h>
using namespace std;
vector<int> gtright(int arr[],int n )
{
    stack<int> s;
    vector<int> v;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()>arr[i])
        {
            v.push_back(arr[i]);
        }
        else if(s.size()>0 && s.top()<=arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return v;
}
int main()
{
    int arr[6]={1,5,3,7,12,66};
    vector<int> v;
    v=gtright(arr,6); 
    reverse(v.begin(),v.end());
    for(int i=0;i<6;i++)
    {
        cout<<v[i]<<endl;
    }

}