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

void solve()
{
	ll r,c,i,j,k,l,n=32;
	map<pair<ll,ll>,ll>a;
	for(i=8;i>0;i-=2)
	{
		for(j=2;j<9;j+=2)
			a[{i,j}]=1;
	}
	for(i=8;i>0;i-=2)
	{
		for(j=1;j<9;j+=2)
			a[{i,j}]=1;
	}
	cin>>r>>c;
	n--;
	a[{r,c}]=0;
	bool f=true;
	vector<pair<ll,ll>>ans;
	while(n>0)
	{
		while(r>0 && c>0 && n>0)
		{
			r++;
			c--;
			if(a[{r,c}])
			{
				a[{r,c}]=0;
				n--;
			}
		}
		ans.push_back({r,c});
		while(r<9 && c<9 && n>0)
		{
			r--;
			c++;
			if(a[{r,c}])
			{
				a[{r,c}]=0;
				n--;
			}
		}
		ans.push_back({r,c});
		if(f)
		{
			r++;
			c++;
		}
		else
		{
			r--;
			c--;
		}
		if(n<1)break;
		ans.push_back({r,c});
	}
	cout<<ans.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
