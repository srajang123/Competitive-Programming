#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 1000000007

//Prime Numbers


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
ll n, l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;
vector<bool>bvisited(N,false);
vector<unordered_map<ll,ll>>pre;

vector<ll>sp(N);
void sieve()
{
	ll i,j;
	sp[1]=1;
	for(i=2;i<N;i++)
		sp[i]=i;
	for(i=4;i<N;i+=2)
		sp[i]=2;
	for(i=3;i*i<N;i++)
	{
		if(sp[i]==i)
		{
			for(j=i*i;j<N;j+=i)
			{
				if(sp[j]==j)
					sp[j]=i;
			}
		}
	}
}

unordered_map<ll,ll>pFactors(ll n)
{
		unordered_map<ll,ll>r;
		while(n!=1)
		{
			r[sp[n]]++;
			n/=sp[n];
		}
		return r;
}
vector<ll> bfs(ll V,vector<vector<ll>>G,ll s,vector<ll>b)
{
	vector<ll>order;
	queue<ll>q;
	bvisited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		order.push_back(s);
		for(auto x:G[s])
		{
			if(!bvisited[x])
			{
				bvisited[x]=true;
				for(auto y:pre[s])
				{
					pre[x][y.first]+=y.second;
				}
				q.push(x);
			}
		}
	}
	return order;
}
vector<bool>dvisited(N,false);
vector<ll> dfs(ll V,vector<vector<ll>>G,ll s)
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
}

//Main Solution
void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            {
                u = up[u][i];
            }
    }
    return up[u][0];
}
void preprocess(ll root,vector<ll>b) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vector<ll>(l + 1));
    dfs(root, root);
	bfs(n+1,adj,1,b);
}
void solve()
{
	ll i,j,k,q,u,v;
	cin>>n;
	vector<ll>b(n+1);
	adj.resize(n+1);
	pre.resize(n+1);
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		pre[i]=pFactors(b[i]);
	}
	preprocess(1,b);
	cin>>q;
	while(q--)
	{
		cin>>u>>v;
		unordered_map<ll,ll>p=pre[u],q=pre[v],r;
		i=lca(u,v);/*
		unordered_set<ll>sa;
	    sa.insert(u);
	    sa.insert(v);
	    sa.insert(i);
		while(u!=i)
		{
		    sa.insert(u);
		    u=up[u][0];
		}
		while(v!=i)
		{
		    sa.insert(v);
		    v=up[v][0];
		}
	    unordered_map<ll,ll>pc;
	    for(auto x:sa)
	    {
	        for(auto y:pFactors(b[x]))
	        {
	            pc[y.first]+=y.second;
	        }
	    }
	    i=1;
	    for(auto x:pc)
	    {
	        i=(i*((x.second+1)%M))%M;
	    }
		*/
		r=pFactors(b[i]);
		for(auto x:p)
		{
			r[x.first]+=x.second;
		}
		for(auto x:q)
		{
			r[x.first]+=x.second;
		}
		for(auto x:pre[i])
		{
			r[x.first]-=x.second;
			r[x.first]-=x.second;
		}
		i=1;
		for(auto x:r)
			i=(i*((x.second+1)%M))%M;
		cout<<i<<"\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    cin>>t;
    sieve();
    while(t--)
    {
        adj.clear();
        up.clear();
        tin.clear();
        tout.clear();
		for(ll i=0;i<pre.size();i++)
			pre[i].clear();
		pre.clear();
        solve();
    }
}
