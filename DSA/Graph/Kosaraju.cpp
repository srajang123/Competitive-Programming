#include<bits/stdc++.h>
using namespace std;

int succ(vector<vector<int>>&G,int x)
{
    return G[x][0];
}
int t=0,n;
vector<int>tin(n+1,0),tout(n+1,0);
void dfs(int s,vector<bool>&vis,vector<vector<int>>&G)
{
    tin[s]=++t;
    vis[s]=true;
    for(auto x:G[s])
    {
        if(!vis[x])
            dfs(x,vis,G);
    }
    vis[s]=++t;
}
int main()
{
    int i,j,k,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<int>>G(n+1);
    while(m--)
    {
        cin>>i>>j;
        G[i].push_back(j);
    }
    vector<bool>vis(n+1,false);
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i,vis,G);
    }
    /*vector<pair<int,int>>b;
    for(i=1;i<=n;i++)
    {
        b.push_back({tout[i],i});
    }
    sort(b.begin(),b.end());
    for(i=0;i<n;i++)
        cout<<b[i].second<<"    "<<b[i].first<<"\n";*/
}