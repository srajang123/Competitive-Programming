#include<bits/stdc++.h>
using namespace std;

/*
    Complexity: O((E+V)logV)
*/
int main()
{
    int n,i,j,k,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>G(n+1);
    vector<bool>vis(n+1,false);
    while(m--)
    {
        cin>>i>>j>>k;
        G[i].push_back({j,k});
        G[j].push_back({i,k});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,1});
    int mn=0;
    while(!q.empty())
    {
        int u=q.top().second;
        int w=q.top().first;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        mn+=w;
        for(auto x:G[u])
        {
            if(!vis[x.first])
            {
                q.push({x.second,x.first});
            }
        }
    }
    cout<<mn<<"\n";
}