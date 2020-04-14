#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 998244353

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
vector<vector<ll>>And(4,vector<ll>(4,0));
vector<vector<ll>>Or(4,vector<ll>(4,1));
vector<vector<ll>>Xor(4,vector<ll>(4,0));
void init()
{
	Or[0][0]=0;
	Or[0][2]=2;
	Or[0][3]=3;
	Or[2][0]=2;
	Or[2][2]=2;
	Or[3][0]=3;
	Or[3][3]=3;
	And[1][1]=1;
	And[1][2]=2;
	And[1][3]=3;
	And[2][1]=2;
	And[2][2]=2;
	And[3][1]=3;
	And[3][3]=3;
	Xor[0][1]=1;
	Xor[0][2]=2;
	Xor[0][3]=3;
	Xor[1][0]=1;
	Xor[1][2]=3;
	Xor[1][3]=2;
	Xor[2][0]=2;
	Xor[2][1]=3;
	Xor[2][3]=1;
	Xor[3][0]=3;
	Xor[3][1]=2;
	Xor[3][2]=1;
}
pair<vector<ll>,ll> ans(ll in,string s,vector<ll>u,char sym)
{
	ll i,j,k,ri=s.size()-1;
	vector<ll>p(4,1);
	for(i=in;i<s.size();i++)
	{
		vector<ll>q(4,0);
		if(s[i]=='(')
		{
			char x='1';
			char n=s[i-1];
			if(n=='|'||n=='^'||n=='&')
				x=n;
			pair<vector<ll>,ll>gg=ans(i+1,s,p,x);
			i=gg.second;
			p=gg.first;
		}
		else if(s[i]==')')
		{
			ri=i;
			break;
		}
		else if(s[i]=='|' && s[i+1]=='#')
		{
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					q[Or[j][k]]=(q[Or[j][k]]+p[j])%M;
				}
			}
			for(j=0;j<4;j++)
			{
				p[j]=q[j];
			}
		}
		else if(s[i]=='^' && s[i+1]=='#')
		{
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					q[Xor[j][k]]=(q[Xor[j][k]]+p[j])%M;
				}
			}
			for(j=0;j<4;j++)
			{
				p[j]=q[j];
			}
		}
		else if(s[i]=='&' && s[i+1]=='#')
		{
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					q[And[j][k]]=(q[And[j][k]]+p[j])%M;
				}
			}
			for(j=0;j<4;j++)
			{
				p[j]=q[j];
			}
		}
	}
	if(sym=='1')
	{
		return {p,ri};
	}
	vector<ll>du(4,0);
	if(sym=='&')
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				du[And[j][k]]=(du[And[j][k]]+u[j]*p[k])%M;
			}
		}
	}
	else if(sym=='|')
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				du[Or[j][k]]=(du[Or[j][k]]+u[j]*p[k])%M;
			}
		}
	}
	else if(sym=='^')
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				du[Xor[j][k]]=(du[Xor[j][k]]+u[j]*p[k])%M;
			}
		}
	}
	return {du,ri};
}
ll exGCD(ll n,ll m,ll &x,ll &y)
{
	if(n==0)
	{
		x=0;
		y=1;
		return M;
	}
	ll x1,y1;
	ll d=exGCD(m%n,n,x1,y1);
	x=y1-(m/n)*x1;
	y=x1;
	return d;
}
ll modinv(ll d)
{
	ll x,y;
	exGCD(d,M,x,y);
	x=(x%M+M)%M;
	return x;
}
void solve()
{
	string s,a;
	cin>>s;
	ll i,j,k,l,d=1;
	vector<ll>p;
	vector<char>q;
	vector<ll>an(4,1);
	bool f=false;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='#')
		{
			d=(d*4)%M;
		}
	}
	pair<vector<ll>,ll> h=ans(0,s,an,'1');
	p=h.first;
	d=modinv(d);
	for(i=0;i<4;i++)
	{
		cout<<(p[i]*d)%M<<" ";
	}
	cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    cin>>t;
	init();
    while(t--)
    {
        solve();
    }
}
