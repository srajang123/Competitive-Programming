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
	ll i,j,k,l,n;
	cin>>n;
	vector<ll>a(n),b(n),c(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
		c[i]=a[i];
	}
	k=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>a[k])
			k=i;
	}
	for(i=k+1;i<n-1;i++)
	{
		if(a[i+1]>a[i])
			a[i+1]=a[i];
	}
	for(i=k-1;i>0;i--)
	{
		if(a[i-1]>a[i])
			a[i-1]=a[i];
	}
	k=0;
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]>a[i])
			k++;
		else
			break;
	}
	for(i=k+1;i<n-1;i++)
	{
		if(b[i+1]>b[i])
			b[i+1]=b[i];
	}
	for(i=k-1;i>0;i--)
	{
		if(b[i-1]>b[i])
			b[i-1]=b[i];
	}
	k=n-1;
	for(i=n-1;i>0;i++)
	{
		if(a[i-1]>a[i])
			k--;
		else
			break;
	}
	for(i=k+1;i<n-1;i++)
	{
		if(c[i+1]>c[i])
			c[i+1]=c[i];
	}
	for(i=k-1;i>0;i--)
	{
		if(c[i-1]>c[i])
			c[i-1]=c[i];
	}
	j=k=l=0;
	for(i=0;i<n;i++)
	{
		j+=a[i];
		k+=b[i];
		l+=c[i];
	}
	if(k>j && k>l)
	{
		for(i=0;i<n;i++)
			a[i]=b[i];
	}
	else if(l>j && l>k)
	{
		for(i=0;i<n;i++)
			a[i]=c[i];
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
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
