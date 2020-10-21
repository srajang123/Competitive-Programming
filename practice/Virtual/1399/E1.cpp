#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 1000000007

/*
	*********************************************************************
	*                             Code By                               *
	*                                                                   *
	*                            Srajan Gupta                           *
	*                            srajang_123                            *
	*                                                                   *
	*********************************************************************
*/
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
vector<vector<pair<ll,ll>>>G(N);/*
vector<ll> bfs(ll s)
{
	vector<ll>order;
	queue<ll>q;
	bvisited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		q.pop();
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
}*/
vector<bool>dvisited(N,false);
vector<ll>cn(N,0);
ll dfs(ll s,ll p=-1)//,map<pair<ll,ll>,ll>&a,vector<pair<ll,ll>>&b)
{
	if(G[s].size()==1 && p!=-1)
	{
		return cn[s]=1;
	}
	ll c=0;
	for(auto x:G[s])
	{
	    if(x.first==p)continue;
		c+=dfs(x.first,s);
	}
	return cn[s]=c;
}
vector<pair<ll,ll>>dp;
ll dfs2(ll s,ll p=-1)//,map<pair<ll,ll>,ll>&a,vector<pair<ll,ll>>&b)
{
	for(auto x:G[s])
	{
	    if(x.first==p)continue;
		dp.push_back({cn[x.first],x.second});
		dfs2(x.first,s);
	}
	return 0;
}
//My Functions

void print(pair<ll,ll>a)
{
	cout<<a.first<<" "<<a.second;
}
void print(vector<ll>a)
{
	for(auto x:a)
		cout<<x<<" ";
}
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
	return a.second<b.second;
}
//Main Solution
bool mysort(pair<ll,ll>a,pair<ll,ll>b)
{
	if(a.first*a.second>=b.first*b.second)
		return true;
	return false;
}
void solve()
{
	ll i,j,k,l,n,s;
	cin>>n>>s;
	for(i=0;i<=n;i++)
	{
		G[i].clear();
		cn[i]=0;
	}
	dp.clear();
	for(i=1;i<n;i++)
	{
		cin>>j>>k>>l;
		G[k].push_back({j,l});
		G[j].push_back({k,l});
	}
	dfs(1);
	/*for(i=0;i<=n;i++)
	    cout<<cn[i]<<" ";
	    cout<<"\n";*/
	dfs2(1);
	sort(dp.begin(),dp.end(),mysort);
	ll c=0;
	for(i=0;i<dp.size();i++)
	{
	    //print(dp[i]);
	    //cout<<"\n";
		c+=dp[i].first*dp[i].second;
	}
	l=0;
	//cout<<c<<"-";
	for(i=0;i<dp.size() && c>s;i++)
	{
		while(c>s && dp[i].second>0)
		{
			j=dp[i].second/2;
			c-=dp[i].first*j;
			dp[i].second=j;
			l++;
		}
	}
	cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
	cin>>t;
    while(t--)
    {
        solve();
    }
}
