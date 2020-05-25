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
	ll a,b,c,i,j,k,l,n,m;
	ll qq,ww,ee;
	string s,t,u;
	cin>>c>>b>>a;
	qq=c;
	ww=b;
	ee=a;
	bool p,q,r;
	p=q=r=false;
	if(b>0)
	{
		q=true;
		b--;
		t.push_back('1');
		t.push_back('0');
		while(b--)
		{
			if(t.back()=='1')
				t.push_back('0');
			else
				t.push_back('1');
		}
	}
	if(c>0)
	{
		k=c+1;
		if(q)
		{
			if(t.back()=='0')
			{
				k--;
				while(k--)
				{
					u.push_back('0');
				}
			}
			else
			{
				k--;
				while(k--)
				{
					u.push_back('0');
				}
				u.push_back('1');
				t.pop_back();
			}
		}
		else
		{
			while(k--)
			{
				u.push_back('0');
			}
		}
	}
	if(a>0)
	{
		k=a+1;
		if(q)
		{
			if(t.front()=='1')
				k--;
		}
		while(k--)
			s.push_back('1');
	}
	s=s+t+u;
	/*
	a=b=c=0;
	for(i=0;i<s.size()-1;i++)
	{
		if(s[i]==s[i+1])
		{
			if(s[i]=='0')
			{
				c++;
			}
			else
			{
				a++;
			}
		}
		else
		{
			b++;
		}
	}
	if(a<ee)
	{
		while(a<ee)
		{
			s="1"+s;
			a++;
		}
	}
	else if(a>ee)
	{
		while(a>ee)
		{
			s.erase(s.begin());
			a--;
		}
	}
	if(c<qq)
	{
		while(c<qq)
		{
			s=s+"0";
			c++;
		}
	}
	else if(c>qq)
	{
		while(c>qq)
		{
			s.pop_back();
			c--;
		}
	}*/
	cout<<s<<"\n";
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
