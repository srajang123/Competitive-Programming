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
ll c=0;

void find(string a,ll i,ll j,ll n,ll cc,vector<string>s,vector<ll>my)
{
	ll y=0,yy=0;
	for(y=0;y<my.size();y++)
		yy+=my[y]==0?1:0;
	if(yy>n-cc)return;
	if(cc==n)
	{
		ll ii,x=0;
		for(ii=0;ii<my.size();ii++)
		{
			x+=my[ii]>0?1:0;
		}
		if(x==my.size())
			c++;
		return;
	}
	ll ii,jj,kk;
	for(ii=i;ii<s.size();ii++)
	{
		jj=0;
		if(ii==i)
			jj=j;
		for(jj;jj<s[ii].size();jj++)
		{
			if(s[ii][jj]==a[cc])
			{
				vector<ll>myo=my;
				myo[ii]++;
				find(a,ii,jj+1,n,cc+1,s,myo);
			}
		}
	}
}
ll solve()
{
	ll n,i,j,k,l,m;
	cin>>n;
	if(n==0)
		return -1;
	unordered_map<string,ll>a;
	unordered_map<string,vector<string>>b;
	string s,t;
	for(i=0;i<n;i++)
	{
		cin>>s;
		a[s]++;
	}
	vector<string>g;
	string p="-1";
	while(true)
	{
		cin>>s;
		if(s=="LAST")
		{
			cin>>t;
			if(t=="CASE")
				break;
			else
			{
				if(p!="-1")
				{
					b[p]=g;	
				}
				g.clear();
				p=s;
				if(a[t]==0)
				{
					g.push_back(s);
				}
			}
		}
		else if(s[0]>='A' && s[0]<='Z')
		{
			if(p!="-1")
			{
				b[p]=g;	
			}
			g.clear();
			p=s;
		}
		else
		{
			if(a[s]==0)
			{
				g.push_back(s);
			}
		}
	}
	if(p!="-1")
			{
				b[p]=g;	
			}
	unordered_map<string,vector<string>>f;
	for(auto x:b)
	{
		t="";
		for(i=0;i<x.first.size();i++)
			t.push_back(int(x.first[i])+32);
		unordered_map<char,ll>z;
		for(i=0;i<t.size();i++)
			z[t[i]]++;
		for(auto y:x.second)
		{
			s="";
			for(i=0;i<y.size();i++)
			{
				if(z[y[i]]!=0)
					s.push_back(y[i]);
			}
			f[t].push_back(s);
		}
	}
	for(auto x:f)
	{
		c=0;
		find(x.first,0,0,x.first.size(),0,x.second,vector<ll>(x.second.size(),0));
		s=x.first;
		transform(s.begin(),s.end(),s.begin(),::toupper);
		if(c!=0)
		{
			cout<<s<<" can be formed in "<<c<<" ways";
		}
		else
		{
			cout<<s<<" is not a valid abbrevation";
		}
		cout<<"\n";
	}
	return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    while(true)
    {
        if(solve()==-1)
			break;
    }
}
