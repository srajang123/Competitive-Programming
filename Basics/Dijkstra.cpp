#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

//Main Solution
vector<vector<pair<ll,ll>>>v(N);
vector<ll>dist(N,INT64_MAX);
vector<bool>vis(N,false);
vector<ll>par(N,-1);
void dijkstra()
{
	dist[0]=0;
	par[0]=0;
	multiset<pair<ll,ll>>s;
	s.insert({0,0});
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
	ll i,j,k,l,m,n;
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
	dijkstra();
	i=n-1;
	bool f=true;
	vector<ll>a(1,n);
	while(f && i!=0)
	{
		a.push_back(par[i]+1);
		i=par[i];
		if(i==-1)
			f=false;
	}
	if(!f)
	{
		cout<<"-1";
		return;
	}
	for(i=a.size()-1;i>=0;i--)
		cout<<a[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
}