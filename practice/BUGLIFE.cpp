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
vector<ll>col(N,-1);
bool dfs(ll V,vector<vector<ll>>G,ll s,ll c)
{
	bool f=true;
	vector<ll>order;
	stack<ll>q;
	q.push(s);
	col[s]=c;
	ll k=0;
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(!dvisited[v])
		{
			order.push_back(v);
			dvisited[v]=true;
		}
		if(col[v]==0)k=1;
		else k=0;
		for(ll i=0;i<G[v].size();i++)
		{
			if(!dvisited[G[v][i]])
			{
				if(col[G[v][i]]==-1||col[G[v][i]]==k)
					col[G[v][i]]=k;
				else
					return false;
				q.push(G[v][i]);
			}
		}
	}
	return f;
}

//Main Solution

void solve()
{
	ll i,j,k,n,m;
	cin>>n>>m;
	vector<vector<ll>>G(n+1);
	while(m--)
	{
		cin>>i>>j;
		G[i].push_back(j);
		G[j].push_back(i);
	}
	for(i=0;i<=n;i++)
	{
		dvisited[i]=false;
		col[i]=-1;
	}
	bool f=true;
	for(i=1;i<=n && f;i++)
	{
		if(!dvisited[i])
		{
			f=dfs(n,G,i,0);
		}
		G[i].clear();
	}
	G.clear();
	if(f)
		cout<<"No suspicious bugs found!\n";
	else
		cout<<"Suspicious bugs found!\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    cin>>t;
	for(ll i=1;i<=t;i++)
    {
		cout<<"Scenario #"<<i<<":\n";
        solve();
    }
}
