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
	ll n,p,q,i,j,k,l;
	cin>>n>>q;
	vector<ll>a(n),b(n),oo(65,0),ee(65,0);
	vector<vector<ll>>d(n,vector<ll>(65,0));
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		j=a[i];
		k=0;
		ll c=0;
		while(j)
		{
			d[i][k++]=j&1;
			j=j>>1;
			c++;
		}
		if(c%2==0)
		{
			for(j=0;j<65;j++)
				ee[j]+=d[i][j];
		}
		else
		{
			for(j=0;j<65;j++)
				oo[j]+=d[i][j];
		}
	}
	while(q--)
	{
		ll o=0,e=0,c=0;
		cin>>p;
		vector<ll>x(65,0);
		j=p;
		k=0;
		while(j)
		{
			x[k++]=j&1;
			j=j>>1;
		}

		for(i=0;i<n;i++)
		{
			b[i]=a[i]^p;
			c=0;
			while(b[i]>0)
			{
				c+=b[i]&1;
				b[i]=b[i]>>1;
			}
			if(c%2==0)
				e++;
			else
				o++;
		}
		cout<<e<<" "<<o<<"\n";
	}
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
