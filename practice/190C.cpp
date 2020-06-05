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
	dvisited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		for(ll i=0;i<G[v].size();i++)
		{
			if(!dvisited[G[v][i]])
			{
				q.push(G[v][i]);
				dvisited[G[v][i]]=true;
				order.push_back(G[v][i]);
			}
		}
	}
	return order;
}

//Main Solution
vector<string>a;
string ans="";
bool f=true;
ll i=0;
void stl()
{
	if(i>=a.size()|| !f)
	{
		f=false;
		return;
	}
	ans+=a[i];
	if(a[i]=="pair")
	{
		if(f)
		{
			i++;
			ans+="<";
			stl();
			ans+=",";
		}
		if(f)
		{
			i++;
			stl();
			ans+=">";
		}
	}
}
void solve()
{
	ll n,i=0;
	string s,ans="";
	cin>>n;
	stack<char>a;
	while(cin>>s)
	{
		cout<<s<<":\n"
		if(i!=0 && a.empty() && (s=="pair"||s=="int"))
		{
			cout<<"Error occurred";
			return;
		}
		if(s=="pair")
		{
			ans+="pair<";
			a.push('<');
		}
		else
		{
			if(!a.empty() && a.top()==','){
				ans+="int,";
				a.pop();
				a.push(',');
			}
			else if(!a.empty() && a.top()==',')
			{
				if(!a.empty() && a.top()==',')
				{
					ans+="int>";
					a.top();
				}
				while(!a.empty() && a.top()=='<')
				{
					ans+=">";
					a.pop();
				}
				if(!a.empty() && a.top()=='<')
				{
					ans+=',';
					a.pop();
					a.push(',');
				}
			}
		}
		i++;
	}
	if(i==1 && s=="int")
		cout<<s;
	else if(!a.empty() || ans=="")
		cout<<"Error occurred";
	else
		cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
