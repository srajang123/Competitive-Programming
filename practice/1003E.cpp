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
vector<ll>b(N,0),c(N,0);
vector<vector<ll>>G(N);
vector<ll> dfs(ll s)
{
	vector<ll>order;
	stack<ll>q;
	dvisited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		for(ll i=0;i<G[v].size();i++)
		{
			if(!dvisited[G[v][i]])
			{
				b[G[v][i]]=b[v]+1;
				q.push(G[v][i]);
				dvisited[G[v][i]]=true;
				order.push_back(G[v][i]);
			}
		}
	}
	return order;
}
//Main Solution

void solve()
{
	set<pair<ll,ll>>a;
	ll n,d,k,i,j,l,m;
	cin>>n>>d>>k;
	if(d>=n)
	{
		cout<<"NO";
		return;
	}
	//vector<vector<ll>>G(n+1);
	vector<ll>lvl(n+1,1);
	l=1;
	for(i=0;i<d-1;i++)
	{
		G[l].push_back(l+1);
		G[l+1].push_back(l);
		a.insert({l,l+1});
		l++;
	}
	l++;
	m=1;
	ll u;
	queue<ll>q;
	q.push(1);
	ll c=n-d-1;
	while(!q.empty() && l<=n)
	{
		ll s=q.front();
		q.pop();
		u=k-G[s].size();
		while(l<=n && u>0)
		{
			G[s].push_back(l);
			G[l].push_back(s);
			a.insert({min(s,l),max(s,l)});
			u--;
			l++;
		}
		for(auto x:G[s])
			q.push(x);
	}
	/*
	for(m;m<=n && l<=n;m++)
	{
		u=G[m].size();
		u=k-u;
		while(u>0 && l<=n)
		{
			G[m].push_back(l);
			G[l].push_back(m);
			a.insert({min(l,m),max(l,m)});
			l++;
			u--;
		}
	}*/

	
	dfs(1);
	l=0;
	j=1;
	for(i=1;i<=n;i++)
	{
		if(b[i]>l)
		{
			l=b[i];
			j=i;
		}
	}
	fill(b.begin(),b.end(),0);
	fill(dvisited.begin(),dvisited.end(),false);
	dfs(j);
	k=0;
	for(i=1;i<=n;i++)
	{
		k=k>b[i]?k:b[i];
	}
	l=max(l,k);
	if(a.size()!=n-1)
	{
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	for(auto x:a)
	{
		cout<<x.first<<" "<<x.second<<"\n";
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
