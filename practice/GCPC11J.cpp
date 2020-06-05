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
vector<bool>dvisited(N,false);
vector<vector<ll>>G(N);
vector<ll>d(N,0);
vector<ll> dfs(ll s)
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
			for(ll i=0;i<G[v].size();i++)
			{
				if(!dvisited[G[v][i]])
				{
					d[G[v][i]]=d[v]+1;
					q.push(G[v][i]);
				}
			}
		}
	}
	return order;
}

//Main Solution

void solve()
{
	ll n,i,j,k,l;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>j>>k;
		G[j].push_back(k);
		G[k].push_back(j);
	}
	dfs(0);
	l=0;
	for(i=0;i<n;i++)
	{
		if(d[i]>d[l])
			l=i;
	}
	k=d[l];
	fill(d.begin(),d.end(),0);
	fill(dvisited.begin(),dvisited.end(),false);
	dfs(l);
	l=0;
	for(i=0;i<n;i++)
	{
		if(d[i]>k)
			k=d[i];
	}
	k=ceil((k*1.0)/2);
	cout<<k<<"\n";
	for(i=0;i<n;i++)
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
	fill(d.begin(),d.end(),0);
	fill(dvisited.begin(),dvisited.end(),false);
        solve();
    }
}
