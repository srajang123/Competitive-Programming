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
ll n;
vector<ll>tree;
ll sum(ll a,ll b)
{
	a+=n;
	b+=n;
	ll s=0;
	while(a<=b)
	{
		if(a%2==1)s+=tree[a++];
		if(b%2==0)s+=tree[b--];
		a/=2;
		b/=2;
	}
	return s;
}
void build(ll node,ll s,ll e,vector<ll>a)
{
	if(s==e)
		tree[node-1]=a[s];
	else
	{
		ll md=(s+e)/2;
		build(2*node,s,md,a);
		build(2*node+1,md+1,e,a);
		tree[node-1]=tree[2*node-1]+tree[2*node];
	}
}
void update(ll node,ll s,ll e,ll i,ll v,vector<ll>a)
{
	if(s==e)
	{
		a[i]+=v;
		tree[node-1]+=v;
	}
	else
	{
		ll md=(s+e)/2;
		if(s<=i && i<=md)
		{
			update(2*node,s,md,i,v,a);
		}
		else
			update(2*node+1,md+1,e,i,v,a);
		tree[node-1]=tree[2*node-1]+tree[2*node];
	}
	
}
ll query()
{
	
}
void solve()
{
	cin>>n;
	tree.resize(2*n-1);
	ll i,j,k,l;
	vector<ll>a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	build(1,0,n-1,a);
	for(auto x:tree)
		cout<<x<<" ";
		cout<<"\n";
	update(1,0,n-1,4,100,a);
	for(auto x:tree)
		cout<<x<<" ";
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
