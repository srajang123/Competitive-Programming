#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>G(n+1);
    vector<int>d(n+1,INT_MAX),vis(n+1,0);
    while(m--)
    {
        cin>>i>>j>>k;
        G[i].push_back({j,k});
        G[j].push_back({i,k});
    }
    d[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,1});
    while(!q.empty())
    {
        pair<int,int>p=q.top();
        q.pop();
        if(vis[p.second])continue;
        vis[p.second]=1;
        for(auto x:G[p.second])
        {
            if(d[p.second]+x.second<d[x.first])
            {
                d[x.first]=d[p.second]+x.second;
                q.push({x.second,x.first});
            }
        }
    }
    for(auto x:d)
        cout<<x<<" ";
}