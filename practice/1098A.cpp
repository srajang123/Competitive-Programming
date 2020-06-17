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
//vector<bool>dvisited(N,false);
vector<vector<ll>>G(N);
vector<bool>dvisited(N,false);
bool f=true;	
vector<ll>a(N),ans(N);
void dfs(ll s,ll c=0)
{
    dvisited[s]=true;
    ll u=INT64_MAX,v,i,j;
    if(a[s]==-1)
    {
        vector<ll>p;
        for(auto x:G[s])
        {
            if(!dvisited[x])
            {
                p.push_back(a[x]);
            }
            else
                v=a[x];
        }
        for(auto x:p)
        {
            if((x-v)<0)f=false;
            u=min(u,x-v);
        }
        if(u==INT64_MAX)u=0;
        ans[s]=u;
    }
    else
        ans[s]=a[s]-c;
    c+=ans[s];
    for(auto x:G[s])
    {
        if(!dvisited[x])
        {
            dfs(x,c);
        }
    }
}

//Main Solution

void solve()
{
    ll i,j,k,n;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        cin>>j;
        G[j].push_back(i);
        G[i].push_back(j);
    }
    for(i=1;i<=n;i++)
        cin>>a[i];
    ans[1]=a[1];
    dfs(1,0);
    k=-1;
    if(f)
    {
        k=0;
        for(i=1;i<=n;i++)
            k+=ans[i];
    }
    cout<<k;
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
