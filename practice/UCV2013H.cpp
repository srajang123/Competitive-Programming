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
vector<vector<ll>>G(1000,vector<ll>(1000));
vector<vector<bool>>visit(1000,vector<bool>(1000,false));
unordered_map<ll,ll>size;
ll cnt=0;
void recur(ll i,ll j,ll n,ll m)
{
	if(i>=n||i<0||j>=m||j<0)return;
	if(G[i][j]==0)return;
	if(visit[i][j])return;
	cnt++;
	visit[i][j]=true;
	recur(i+1,j,n,m);
	recur(i,j+1,n,m);
	recur(i-1,j,n,m);
	recur(i,j-1,n,m);
}
ll solve()
{
	ll i,j,k,n,m;
	cin>>n>>m;
	if(n==m && n==0)return -1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			visit[i][j]=false;
			cin>>G[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!visit[i][j] && G[i][j])
			{
				cnt=0;
				recur(i,j,n,m);
				size[cnt]++;
			}
		}
	}
	vector<pair<ll,ll>>a;
	cnt=0;
	for(auto x:size)
	{
		a.push_back(x);
		cnt+=x.second;
	}
	sort(a.begin(),a.end());
	cout<<cnt<<"\n";
	for(auto x:a)
	{
		cout<<x.first<<" "<<x.second<<"\n";
	}
	size.clear();
	a.clear();
	return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(true)
    {
        if(solve()==-1)break;
    }
}
