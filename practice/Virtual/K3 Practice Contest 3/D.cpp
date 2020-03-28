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
	ll i,j,k,n,l;
	string s;
	cin>>n>>s;
	ll p,q,r,t,u,v;
	p=q=r=0;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='0')
			p++;
		else if(s[i]=='1')
			q++;
		else
			r++;
	}
	t=u=v=n/3;
	t=p-t;
	u=q-u;
	v=r-v;
	if(u>0 && v>0)
	{
		for(i=0;i<s.size() && u>0 && v>0;i++)
		{
			if(s[i]=='1')
			{
				s[i]='0';
				u--;
			}
			else if(s[i]=='2')
			{
				s[i]='0';
				v--;
			}
		}
	}
	else if(t>0 && u>0)
	{
		for(i=s.size()-1;i>=0 && u>0 && v>0;i--)
		{
			if(s[i]=='1')
			{
				s[i]='2';
				u--;
			}
			else if(s[i]=='0')
			{
				s[i]='2';
				t--;
			}
		}
	}
	else if(t>0 && v>0)
	{
		for(i=0;i<s.size() && v>0;i++)
		{
			if(s[i]=='2')
			{
				s[i]=='1';
				v--;
			}
		}
		for(i=s.size()-1;i>=0 && t>0;i--)
		{
			if(s[i]=='0')
			{
				s[i]='1';
				t--;
			}
		}
	}
	else if(t>0)
	{
		for(i=s.size()-1;i>=0 && v<0;i--)
		{
			if(s[i]=='0')
			{
				s[i]='2';
				v++;
			}
		}
		for(i=s.size()-1;i>=0 && u<0;i--)
		{
			if(s[i]=='0')
			{
				s[i]='1';
				u++;
			}
		}
	}
	else if(v>0)
	{
		for(i=0;i<s.size() && t<0;i++)
		{
			if(s[i]=='2')
			{
				s[i]='0';
				t++;
			}
		}
		for(i=0;i<s.size() && u<0;i++)
		{
			if(s[i]=='2')
			{
				s[i]='1';
				u++;
			}
		}
	}
	else if(u>0)
	{
		for(i=0;i<s.size() && t<0;i++)
		{
			if(s[i]=='1')
			{
				s[i]='0';
				t++;
			}
		}
		for(i=s.size()-1;i>=0 && v<0;i--)
		{
			if(s[i]=='1')
			{
				s[i]='2';
				v++;
			}
		}
	}
	cout<<s;
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
