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

void solve()
{
	string s;
	unordered_map<string,ll>a;
	for(ll ii=1;ii<=3;ii++)
	{
		cin>>s;
		a[s]++;
	}
	ll j=0,k=0,c=0;
	bool f=true;
	for(auto x:a)
	{
		if(x.second==3)
		{
			f=false;
		}
	}
	if(f)
	{
		c=INT64_MAX;
		for(auto x:a)
		{
			j=x.second;
			c=j>c?c:j;
		}
	}
	if(f)
	{
		vector<vector<ll>>b(26);
		k=0;
		for(auto x:a)
		{
			string t=x.first;
			b[t[1]-'a'].push_back(t[0]-'0');
		}
		ll i;
		for(i=0;i<26;i++)
			sort(b[i].begin(),b[i].end());
		for(i=0;i<26;i++)
		{
			if(b[i].size()==3)
			{
				if(b[i][0]+1==b[i][1] && b[i][1]+1==b[i][2])
					f=false;
			}
		}
		if(f)
		{
			k=3;
			for(i=0;i<26;i++)
			{
				if(b[i].size()==1)
				{
					k=k>1?1:k;
				}
				else if(b[i].size()==2)
				{
					if(b[i][0]+1==b[i][1])
						k=k>1?1:k;
					else
						k=k>2?2:k;
				}
				else if(b[i].size()==3)
				{
					if(b[i][0]+1==b[i][1]||b[i][1]+1==b[i][2])
						k=k>1?1:k;
					else
						k=k>2?2:k;
				}
			}
		}
	}
	c=c>k?k:c;
	cout<<c;
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
