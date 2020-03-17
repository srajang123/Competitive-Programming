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

void solve()
{
	ll i,j,k,n;
	string s;
	cin>>n;
	vector<ll>a;
	while(n)
	{
		cin>>s;
		if(s=="pair")
		{
			a.push_back(1);
		}
		else
		{
			a.push_back(0);
			n--;
		}
		a.push_back(-1);
	}
	j=0;
	vector<ll>b;
	for(i=0;i<a.size();i++)
	{
		if(a[i]!=1 && a[i]!=0)
			continue;
		if(a[i]==1)
		{
			/*if(b.size()>0)
			{
				b[b.size()-1]--;
			}*/
			b.push_back(2);
			a[i+1]=2;
		}
		else if(b.size()>0)
		{
			j=b.size()-1;
			b[j]--;
			if(b[j]==0)
			{
				b.pop_back();
				a[i+1]=3;
				if(b.size()>0)
				{
					if(b.back()==1)
						a.insert(a.begin(),i+2,4);
				}
				while(b.size()>0)
				{
					j=b.size()-1;
					b[j]--;
					if(b[j]==0)
					{
						b.pop_back();
						a.insert(a.begin()+i+1,3);
						if(b.size()>0)
						{
							if(b.back()==1)
								a.insert(a.begin(),i+2,4);
						}
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				a[i+1]=4;
			}
		}
	}
	if(b.size()>0)
	{
		cout<<"Error occurred";
		return;
	}
	for(i=0;i<a.size();i++)
	{
		switch (a[i])
		{
		case 0:	cout<<"int";
				break;
		case 1: cout<<"pair";
				break;
		case 2: cout<<"<";
				break;
		case 3: cout<<">";
				break;
		case 4: cout<<",";
				break;
		}
	}
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
