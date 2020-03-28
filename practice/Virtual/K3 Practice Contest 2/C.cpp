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
			for(j=i*i;j<=N;j++)
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

//Main 
string trim(string s,vector<ll>a)
{
	string b;
	ll i,j,k=1;
	i=0;
	for(i=0;i<s.size();i++)
	{
		if(k==1 && (s[i]=='0'||a[i]==1))
		{

		}
		else
		{
			k=0;
			if(a[i]!=1)
				b.push_back(s[i]);
		}
	}
	if(b.size()==0)
		b.push_back('0');
	return b;
}
bool get(string s,vector<ll>a)
{
	ll i,j=0;
	for(i=0;i<s.size();i++)
	{
		if(a[i]!=1)
		{
			j+=s[i]-48;
		}
	}
	if(j%3==0)return true;
	return false;
}
bool check(string s,vector<ll>a)
{
	ll i,j,k;
	k=0;
	ll n=s.size();
	i=0;
	while(i<n)
	{
		if(s[i]=='0')
			k++;
		if(s[i]=='0' ||a[i]==1)
			i++;
		else
		{
			break;
		}
	}
	if(k>0 && i==n)
		return get(s,a);
	else if(i==n)
		return false;
	else
	{
		return get(s,a);
	}
	
}
void solve()
{

	string s;
	ll i,j,k,n,l=0;
	cin>>s;
	vector<vector<ll>>a(3);
	vector<ll>b(s.size(),0);
	for(i=0;i<s.size();i++)
	{
		j=s[i]-48;
		l+=j;
		a[j%3].push_back(i);
	}
	bool f=true,t=false;
	ll c=0;
	string u;
	vector<string>ans;
	if(l%3==0)
		ans.push_back(s);
	else if(l%3==1)
	{
		for(i=s.size()-1;i>=0;i--)
		{
			j=s[i]-48;
			if(j%3==1)
			{
				t=true;
				b[i]=1;
				break;
			}
		}
		if(check(s,b))
		{
			u=trim(s,b);
			ans.push_back(u);
		}
		//if(!check(s,b))
		{
			c=0;
			t=false;
			fill(b.begin(),b.end(),0);
			for(i=s.size()-1;i>=0;i--)
			{
				j=s[i]-48;
				if(j%3==2)
				{
					c++;
					b[i]=1;
				}
				if(c==2)
				{
					t=true;
					break;
				}
			}
			if(check(s,b))
			{
				u=trim(s,b);
				ans.push_back(u);
			}
		}
	}
	else if(l%3==2)
	{
		for(i=s.size()-1;i>=0;i--)
		{
			j=s[i]-48;
			if(j%3==2)
			{
				t=true;
				b[i]=1;
				break;
			}
		}
		if(check(s,b))
		{
			u=trim(s,b);
			ans.push_back(u);
		}
		//if(!check(s,b))
		{
			c=0;
			t=false;
			fill(b.begin(),b.end(),0);
			for(i=s.size()-1;i>=0;i--)	
			{
				j=s[i]-48;
				if(j%3==1)
				{
					c++;
					b[i]=1;
				}
				if(c==2)
				{
					t=true;
					break;
				}
			}
			if(check(s,b))
			{
				u=trim(s,b);
				ans.push_back(u);
			}
		}
	}
	if(ans.size()>0)
	{
		ll m=0;
		for(i=0;i<ans.size();i++)
		{
			if(ans[i].size()>ans[m].size())
				m=i;
		}
		s=ans[m];
		cout<<s;
	}
	else
		cout<<"-1";
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
