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
map<pair<ll,ll>,ll>mp;
bool dfs(ll s)
{
	bool f=false;
	stack<ll>q;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(!dvisited[v])
		{
			dvisited[v]=true;
			for(ll i=0;i<G[v].size();i++)
			{
				if(mp[{v,G[v][i]}])
				{
					mp[{v,G[v][i]}]=0;
					mp[{G[v][i],v}]=0;
					f=true;
				}
				if(!dvisited[G[v][i]])
				{
					q.push(G[v][i]);
				}
			}
		}
	}
	return f;
}
vector<vector<ll>>H(N);
void dfs(ll s,ll p)
{
	G[s].push_back(p);
	for(auto x:H[s])
	{
		if(x!=p)
		{
			dfs(x,s);
		}
	}
}
//Main Solution

void solve()
{
	ll n,i,j,k,l;
	cin>>n;
	for(i=1;i<n;i++)
	{
		 cin>>j>>k>>l;
		 if(l==2)
		 {
			mp[{j,k}]=1;
			mp[{k,j}]=1;
		 }
		 H[j].push_back(k);
		 H[k].push_back(j);
	}
	vector<ll>ans;
	dfs(1,1);
	for(i=n;i>=1;i--)
	{
		if(!dvisited[i])
		{
			if(dfs(i))
			{
				ans.push_back(i);
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(auto x:ans)
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
