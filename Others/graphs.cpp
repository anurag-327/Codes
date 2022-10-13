#include<bits/stdc++.h>
using namespace std;
void dfs(int vertex,vector<int> g[],bool vis[])
{
    cout<<vertex<<endl;
    vis[vertex]=true;
    for(int child:g[vertex])
    {
        dfs(child);
    }
}
int main()
{
    cout<<"HI";
    int n,m;
    cin>>n>>m;
    bool vis[n]={0};
    vector<int> g1[n];
    int g2[n][n];
    for(int i=0;i<m;i++)
    {
        cout<<"HI"<<endl;
       int v1,v2;
       cin>>v1>>v2;
       g1[1].push_back(v2);
       g1[2].push_back(v1);

    }
    dfs(1,g1,vis);
    return 0;
}