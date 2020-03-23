#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

//Main Solution
vector<vector<pair<ll,ll>>>v(N);
vector<ll>dist(N,INT64_MAX);
vector<bool>vis(N,false);
vector<ll>par(N,-1);
void dijkstra(ll st)
{
    dist[st]=0;
    par[st]=0;
    multiset<pair<ll,ll>>s;
    s.insert({0,st});
    while(!s.empty())
    {
        pair<ll,ll>p=*s.begin();
        s.erase(s.begin());
        ll x=p.second;
        ll w=p.first;
        if(vis[x])continue;
        vis[x]=true;
        for(ll i=0;i<v[x].size();i++)
        {
            ll e=v[x][i].first;
            ll w=v[x][i].second;
            if(dist[x]+w<dist[e])
            {
                dist[e]=dist[x]+w;
                par[e]=x;
                s.insert({dist[e],e});
            }
        }
    }
}
void solve()
{
    ll i,j,k,l,m,n,s;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>j>>k>>l;
        j--;
        k--;
        v[j].push_back({k,l});
        v[k].push_back({j,l});
        par[j]=k;
        par[k]=j;
    }
    cin>>s;
    dijkstra(s-1);
    for(i=0;i<n;i++)
    {
        if(i==s-1)continue;
        if(dist[i]==INT64_MAX)
            cout<<"-1 ";
        else
            cout<<dist[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        fill(dist.begin(),dist.end(),INT64_MAX);
        solve();
    }
}