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
vector<vector<ll>>G(N);
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
}
vector<bool>dvisited(N,false);
vector<ll> dfs(ll s)
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

void solve()
{
	ll i,j,k,l,n,m,c=0;
	string s;
	cin>>n>>k>>s;
	l=0;
	vector<pair<ll,ll>>b;
	j=-1;
	for(i=0;i<n;i++)
	{
		if(s[i]=='L')
		{
			l++;
			if(j==-1)
				j=i;
		}
		else
		{
			if(l>0)
			{
				b.push_back({l,j});
			}
			l=0;
			j=-1;
		}
	}
	if(l>0)
	{
		b.push_back({l,j});
	}
	sort(b.begin(),b.end());
	for(i=0;i<b.size() && k>0;i++)
	{
		j=b[i].second;
		l=b[i].first;
		if(j==0||j+l>=n)continue;
		while(l>0 && k>0)
		{
			s[j]='W';
			j++;
			l--;
			k--;
		}
	}
	if(k>0)
	{
		j=-1;
		for(i=0;i<n;i++)
		{
			if(s[i]=='W')
			{
				j=i;
				break;
			}
		}
		if(j==-1)j=n;
		for(i=j-1;k>0 && i>=0;i--)
		{
			s[i]='W';
			k--;
		}
		for(i=j+1;k>0 && i<n;i++)
		{
			if(s[i]=='L')
			{
				s[i]='W';
				k--;
			}
		}
	}
	c=0;
	l=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='W')
		{
			c++;
			if(l!=0)
				c++;
			l++;
		}
		else
			l=0;
	}
	cout<<c<<"\n";
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
