#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define N 1001
#define M 998244353
//vector<bool> dvisited(N, false);
ll p, qq;
bool f;
vector<ll> G[N];
vector<bool>dvisited(N,false);
ll c=0;
void dfs(ll s,ll d=-1)
{
    dvisited[s]=true;
    if(G[s].size()>j)
        c++;
    ll j=G[s].size();
    if(d!=-1)
        j--;
    for(auto x:G[s])
    {
        if(!dvisited[x])
        {
            dfs(x,j);
        }
    }
}

//Main Solution

void solve()
{
    ll n,m,i,j,k,l;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>j>>k;
        G[j].push_back(k);
        G[k].push_back(j);
    }
    for(i=1;i<=n;i++)
    {
        if(!dvisited[i])
            dfs(i);
    }
    cout<<c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    while (t--)
    {
        solve();
    }
}
