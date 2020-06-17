#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 998244353 

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
vector<bool>dvisited(N,false);
vector<vector<ll>>G(N);
bool f=true;
vector<ll>a(N,-1);
vector<ll> dfs(ll s,ll c)
{
	vector<ll>order;
	stack<ll>q;
	q.push(s);
	a[s]=c;
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(!dvisited[v])
		{
			order.push_back(v);
			dvisited[v]=true;
		}
		c=a[v]^1;
		for(ll i=0;i<G[v].size();i++)
		{
			if(a[G[v][i]]==-1||a[G[v][i]]==c)
				a[G[v][i]]=c;
			else
			{
				//cout<<G[v][i]<<","<<v<<"+"<<c<<"\n";
				f=false;
			}
			if(!dvisited[G[v][i]])
			{
				q.push(G[v][i]);
			}
		}
		/*for(ll o=1;o<=4;o++)
			cout<<a[o]<<" ";
		cout<<"\n";*/
	}
	return order;
}

//Main Solution
void init(ll n)
{
	f=true;
	for(ll i=1;i<=n;i++)
	{
		a[i]=-1;
		dvisited[i]=false;
	}
}
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
	init(n);
	vector<vector<ll>>p(2);
	for(i=1;i<=n;i++)
	{
		if(!dvisited[i])
		{
			vector<ll>g=dfs(i,0);
			if(f)
			{
				k=1;
				for(auto u:g)
				{
					k*=a[u]==0?2:1;
				}
			}
			else
				k=0;
			for(auto x:g)
			{
				dvisited[x]=false;
				a[x]=-1;
			}
			f=true;
			g.clear();
			g=dfs(i,1);
			if(f)
			{
				l=1;
				for(auto u:g)
					l*=a[u]==0?2:1;
			}
			else
				l=0;
			p[0].push_back(k);
			p[1].push_back(l);
			g.clear();
		}
	}
	k=1;
	for(i=0;i<p[0].size();i++)
	{
		j=(p[0][i]+p[1][i])%M;
		k=(k*j)%M;
	}
	cout<<k<<"\n";
	for(i=1;i<=n;i++)
		G[i].clear();
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
        solve();
    }
}
