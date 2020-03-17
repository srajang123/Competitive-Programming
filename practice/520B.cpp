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
map<ll,ll>level;
ll ans=INT64_MAX;
vector<ll> bfs(ll V,vector<vector<ll>>G,ll s, ll e)
{
	vector<ll>order;
	queue<ll>q;
	q.push(s);
	level[s]=0;
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		bvisited[s]=true;
		//order.push_back(s);
		if(s==e)
		{
			ans=ans>level[s]?level[s]:ans;
			return order;
		}
		if(s>20000)
			continue;
		for(auto x:G[s])
		{
			if(!bvisited[x])
			{
				q.push(x);
				level[x]=level[s]+1;
			}
		}
	}
	return order;
}

vector<bool>dvisited(N,false);
vector<ll> dfs(ll V,ll e,ll s)
{
	vector<ll>order;
	stack<ll>q;
	q.push(s);
	level[s]=1;
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(v==e)
		{
			ans=ans>level[v]?level[v]:ans;
			continue;
		}
		if(!dvisited[2*v] && 2*v<=2*e)
		{
			q.push(2*v);
			level[2*v]=level[v]+1;
		}
		if(!dvisited[v-1])
		{
			q.push(v-1);
			level[v-1]=level[v]+1;
		}
	}
	return order;
}

//Main Solution

void solve()
{
	ll n,i,j,k,l,m;
	cin>>n>>m;
	vector<vector<ll>>a(20001);
	for(i=1;i<=20000;i++)
	{
		a[i].push_back(i-1);
		a[i].push_back(2*i);
	}
	bfs(n,a,n,m);
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
