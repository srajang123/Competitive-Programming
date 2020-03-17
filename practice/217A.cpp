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
	ll i,j,k,n,m;
	cin>>m;
	map<ll,vector<ll>>d;
	set<ll>s;
	map<ll,ll>t;
	for(i=0;i<m;i++)
	{
		cin>>j>>k;
		d[j-1].push_back(k-1);
		s.insert(j-1);
		s.insert(k-1);
	}
	vector<vector<ll>>a(s.size());
	i=0;
	for(auto x:s)
	{
		t[x]=i;
		i++;
	}
	for(auto x:d)
	{
		for(auto y:x.second)
		{
			a[t[x.first]].push_back(t[y]);
		//	a[t[y]].push_back(t[x.first]);
		}
	}
	//exit(0);
	ll c=0;
	for(auto x:a)
	{
		for(auto y:x)
			cout<<y<<" ";
		cout<<"\n";
	}
	for(i=0;i<a.size();i++)
	{
		if(!dvisited[i])
		{
			for(auto x:dfs(a.size(),a,i))
				cout<<x<<" ";
			cout<<"\n";
			c++;
		}
	}
	//exit(0);
	cout<<c<<"\n";
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
