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
	ll i,j,k,n,m;
	string a,b;
	cin>>n>>a>>b;
	vector<unordered_set<ll>>h;
	bool f=true,c=true;
	for(i=0;i<n;i++)
	{
		unordered_set<ll>t;
		if(a[i]!=b[i])
		{
			t.insert(i+1);
			//char p=b[i];
			//cout<<i<<":"<<b[i]<<"\n";
			f=false;
			for(j=0;j<n;j++)
			{
				if(a[j]!=b[j] && b[j]==b[i])
				{
					if(a[j]>b[i])
					{
						t.insert(j+1);
						//a[j]=b[i];
					}
				}
				else if(a[j]==b[i])
				{
					t.insert(j+1);
					f=true;
				}
			}
			if(f)
			{
				for(auto z:t)
				{
					a[z-1]=b[i];
				}
			}
			else
				break;
			h.push_back(t);
			t.clear();
		}
	}
	//cout<<a<<"\n"<<b<<"\n";
	if(a==b)
	{
		cout<<h.size()<<"\n";
		for(auto x:h)
		{
			cout<<x.size()<<" ";
			for(auto y:x)
				cout<<y-1<<" ";
			cout<<"\n";
		}
	}
	else
		cout<<"-1\n";
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
