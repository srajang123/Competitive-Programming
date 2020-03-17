#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define M 1000000007

//Prime Numbers

//vector<bool>prime(N+1,true);
/*void sieve()
{
	ll i,j,k;
	prime[0]=prime[1]=false;
	for(i=2;i*i<=N;i++)
	{
		if(prime[i])
		{
			for(j=i*i;j<=N;j++)
			{
				prime[j]=false;
			}
		}
	}
}*/

//Exponentiation

ll power(ll a,ll b)
{
	ll r=1;
	while(b)	
	{
		if(b%2==1)
			r=r*a;
		b/=2;
		a*=a;		
	}
	return r;
}
ll power(ll a,ll b,ll m)
{
	a=a%m;
	ll r=1;
	while(b)	
	{
		if(b%2==1)
			r=(r*a)%m;
		b/=2;
		a=(a*a)%m;		
	}
	return r;
}

//Prime Factors

vector<ll> factors(ll n)
{
	vector<ll>r;
	ll i,j;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			r.push_back(i);
			if(n/i!=i)
				r.push_back(n/i);
		}
	}
	return r;
}

//GCD
ll gcd(ll a,ll b)
{
	if(b>a)
	{
		ll t=a;
		a=b;
		b=t;
	}
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
//Graphs
vector<vector<pair<ll,ll>>>G(N);
vector<ll> dijkstra(ll s,ll n)
{
	vector<ll>d(n,INT64_MAX);
	vector<bool>bvisited(n,false);
	vector<ll>par(n,-1);
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<G[i].size();j++)
		{
			par[G[i][j].first]=i;
		}
	}
	d[s]=0;
	queue<pair<ll,ll>>q;
	q.push({0,s});
	while(!q.empty())
	{
		s=q.front().second;
		q.pop();
		if(bvisited[s])continue;
		bvisited[s]=true;
		for(auto x:G[s])
		{
			ll p=x.first,r=x.second;
			if(d[s]+r<d[p])
			{
				d[p]=d[s]+r;
				q.push({-d[p],p});
				par[p]=s;
			}
		}
		if(q.size()>500)
		{
			cout<<"EXTRA";
			return par;
		}
	}
	return par;
}
//vector<bool>dvisited(N,false);
/*vector<ll> dfs(ll V,vector<vector<ll>>G,ll s)
{
	vector<ll>order;
	stack<ll>q;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(!dvisited[v])
		{
			order.push_back(v);
			dvisited[v]=true;
		}
		for(ll i=0;i<G[v].size();i++)
		{
			if(!dvisited[G[v][i]])
			{
				q.push(G[v][i]);
			}
		}
	}
	return order;
}*/

//Main Solution

void solve()
{
	ll i,j,k,n,m,l;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>j>>k>>l;
		G[j-1].push_back({k-1,l});
		G[k-1].push_back({j-1,l});
	}
	vector<ll>par=dijkstra(0,n);
	vector<ll>ans(1,n);
	G.clear();
	G.shrink_to_fit();
	i=n-1;
	bool f=true;
	while(i!=0 && f)
	{
		ans.push_back(par[i]+1);
		i=par[i];
		if(i==-1)
			f=false;
	}
	if(!f)
	{
		cout<<"-1";
		return;
	}
	for(i=ans.size()-1;i>=0;i--)
		cout<<ans[i]<<" ";
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
