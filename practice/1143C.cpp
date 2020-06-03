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
vector<vector<ll>>G(N);
vector<bool>dvisited(N,false);
vector<ll>ord;
vector<ll>p(N),qr(N),rr(N,0);
void dfs(ll s)
{
	stack<ll>q;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(!dvisited[v])
		{
			dvisited[v]=true;
		}
		if(qr[v]==1 && G[v].size()==0)rr[v]=1;
		for(ll i=0;i<G[v].size();i++)
		{
			if(!dvisited[G[v][i]])
			{
				if(qr[v]==1)
				{
					if(qr[G[v][i]])
						rr[v]++;
				}
				q.push(G[v][i]);
			}
		}
		if(rr[v]>0 && G[v].size()<=rr[v])
			ord.push_back(v);
	}
}

//Main Solution

void solve()
{
	ll i,j,k,n,m;
	cin>>n;
	ll r;
	for(i=1;i<=n;i++)
	{
		cin>>p[i]>>qr[i];
		if(p[i]==-1)
			r=i;
		else
		{
			//G[i].push_back(p[i]);
			G[p[i]].push_back(i);
		}
	}
	for(i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	dfs(r);
	/*for(i=1;i<=n;i++)
	{
		cout<<rr[i]<<" ";
	}
	cout<<"\n";*/
	if(ord.size()==0)
	{
		cout<<"-1";
		return;
	}
	sort(ord.begin(),ord.end());
	for(auto x:ord)
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
