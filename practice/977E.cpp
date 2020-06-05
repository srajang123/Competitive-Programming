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
vector<ll>G[N];
ll ans=0;
vector<ll>in(N,-1);
unordered_set<ll> dfs(ll s)
{
	unordered_set<ll>order;
	stack<ll>q;
	q.push(s);
	bool f=false,p=true;
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		in[v]+=2;
		if(!dvisited[v])
		{
			order.insert(v);
			dvisited[v]=true;
			if(G[v].size()!=2)
				p=false;
			for(ll i=0;i<G[v].size();i++)
			{
				if(!dvisited[G[v][i]])
				{
					q.push(G[v][i]);
				}
			}
		}
	}
	if(p)
		ans++;
	return order;
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
	cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
