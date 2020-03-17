#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 1000000007

//Prime Numbers

vector<bool>prime(N+1,true);
void sieve()
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
}

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
vector<bool>bvisited(N,false);
vector<ll> bfs(ll V,vector<vector<ll>>G,ll s)
{
	vector<ll>order;
	queue<ll>q;
	bvisited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		order.push_back(s);
		for(auto x:G[s])
		{
			if(!bvisited[x])
			{
				bvisited[x]=true;
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
bool clrgrp(vector<vector<ll>>a,ll p,vector<ll>c,ll d)
{
	if(c[p]!=-1 && c[p]!=d)
		return false;
	c[p]=d;
	bool n=true;
	for(ll i=0;i<a.size();i++)
	{
		if(a[p][i])
		{
			if(c[i]!=-1)
				n&=(a,c,i,1-d);
			if(c[i]!=-1 && c[i]!=1-d)
				return false;
		}
		if(!n)
			return n;
	}
	return true;
}
bool bip(vector<set<ll>>a)
{
	ll n=a.size();
	bool f=true;
	vector<ll>s(n-1,-1);
	queue<ll>q;
	for(ll i=0;i<n;i++)
	{
		if(s[i]==-1)
		{
			q.push(i);
			s[i]=0;
			while(!q.empty())
			{
				ll v=q.front();
				q.pop();
				for(ll u:a[v])
				{
					if(s[u]==-1)
					{
						s[u]=s[v]^1;
						q.push(u);
					}
					else
						f&=s[u]!=s[v];
				}
			}
		}
	}
	return f;
}
bool chk(vector<set<ll>>a)
{
		int n;
	vector<set<int>> adj=a;

	vector<int> side(n, -1);
	bool is_bipartite = true;
	queue<int> q;
	for (int st = 0; st < n; ++st) {
		if (side[st] == -1) {
			q.push(st);
			side[st] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : adj[v]) {
					if (side[u] == -1) {
						side[u] = side[v] ^ 1
						q.push(u);
					} else {
						is_bipartite &= side[u] != side[v];
					}
				}
			}
		}
	}
	return is_bipartite;
}
bool isBi(vector <set <ll> > g, ll u)
{
  vector <ll> color(n+1,-1);
  
  color[u] = 1;
  
  queue <ll> q;
  q.push(u);
  
  while(!q.empty())
  {
    u = q.front();
    q.pop();
    
    for(auto v:g[u])
    {
      if(color[v]==-1)
      {
        color[v] = 1 - color[u];
        q.push(v);
      }
      else if(color[v]==color[u]) 
        return false;
    }
  }
  
  return true;
}
void solve()
{
	ll n,m,z,x,y;
	cin>>n>>m;
	vector <set<ll>> g(n+1);
  
  while(m--)
  {
    cin >> z >> x >> y;
    if(z==1)
    {
      g[x].insert(y);
      g[y].insert(x);
    }
    else
    {
      bool ex=false,ey=false;
      if(g[x].find(y)==g[x].end())
      {
        g[x].insert(y);
        ex = true;
      }
      if(g[y].find(x)==g[y].end())
      {
        g[y].insert(x);
        ey = true;
      }
      
      if(isBi(g,x))
      {
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
      
      if(ex) g[x].erase(y);
      if(ey) g[y].erase(x);
    }
  }
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
