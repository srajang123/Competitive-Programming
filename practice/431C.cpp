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
vector<vector<ll>>G(N),a(101);
vector<vector<ll>>dist(N,vector<ll>(101,INT64_MAX));
vector<ll> bfs(ll i)
{
	vector<ll>order;
	queue<ll>q;
	//q.push(s);
    for(auto x:a[i])
    {
        q.push(x);
        dist[x][i]=0;
    }
	while(!q.empty())
	{
		s=q.front();
        bvisited[s]=true;
		order.push_back(s);
		for(auto x:G[s])
		{
			if(!bvisited[x])
			{
				bvisited[x]=true;
                if(dist[x][i]<=dist[s][i]+1)
                    continue;
                dist[x][i]=dist[s][i]+1;
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
    ll n,k,d,i,j,l;
    cin>>n>>k>>d;
    vector<vector<ll>>dp(n+1,vector<ll>(2));
    dp[0][0]=dp[0][1]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][0]=0;
        for(j=1;j<=min(i,d-1);j++)
        {
            dp[i][0]=(dp[i][0]+dp[i-1][0])%M;
        }
        dp[i][1]=0;
        for(j=d;j<=min(i,k);j++)
        {
            dp[i][1]=(dp[i-1][0]+dp[i][1])%M;
        }
        for(j=1;j<=min(i,k);j++)
        {
            dp[i][1]=(dp[i-j][1]+dp[i][1])%M;
        }
    }
    cout<<dp[n][1];
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
