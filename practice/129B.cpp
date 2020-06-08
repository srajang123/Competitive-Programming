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
			for(j=i*i;j<=N;j+=i)
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
vector<bool>dvisited(N,false),chk(N,false);
vector<set<ll>>G(N);
vector<ll> dfs(ll s,ll n)
{
	vector<ll>order;
	stack<ll>q;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(!dvisited[v] && !chk[v])
		{
			dvisited[v]=true;
			if(G[v].size()==1)
			{
			    chk[v]=true;
			    order.push_back(v);
			}
			for(auto x:G[v])
			{
				if(!dvisited[x] && !chk[x])
				{
					q.push(x);
				}
			}
		}
	}
	for(auto x:order)
	{
	    G[x].clear();
    	for(ll i=1;i<=n;i++)
    	{
    	    G[i].erase(x);
    	}
	}
	return order;
}

//Main Solution

void solve()
{
	ll n,m,i,j,k,u=0;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>j>>k;
		G[j].insert(k);
		G[k].insert(j);
	}
	bool f=true;
	k=0;
	while (f)
	{
		for(i=1;i<=n;i++)
			dvisited[i]=false;
		for(i=1;i<=n;i++)
		{
			if(!dvisited[i] && !chk[i])
				dfs(i,n);
		}
		j=0;
		for(i=1;i<=n;i++)
		{
			j+=chk[i]?1:0;
		}
		if(j<=k)
			f=false;
		else
		    u++;
		k=j;
	}
	k=0;
	for(i=1;i<=n;i++)
		k+=chk[i]?0:1;
	cout<<u;
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