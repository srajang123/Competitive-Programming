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
vector<vector<ll>>G(N),g(N);
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
vector<ll>in(N,0);
unordered_set<ll>st;
void dfs(ll s,ll p=-1)
{
    dvisited[s]=true;
    st.insert(s);
    if(p!=-1)
    {
        if(in[s]==1)
        {
            g[s].push_back(p);
            in[p]=1;
        }
        else
        {
            g[p].push_back(s);
            in[s]=1;
        }
    }
    for(auto x:G[s])
    {
        if(in[x]==0 && x!=p)
            dfs(x,s);
    }
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
vector<ll>tree(N,0);
ll n;
ll po(ll k)
{
    return k&-k;
}
ll sum(ll k)
{
    ll s=0;
    while(k>0)
    {
        s+=tree[k];
        k-=k&-k;
    }
    return s;
}
void add(ll k,ll x)
{
    while(k<=n)
    {
        tree[k]+=x;
        k+=k&-k;
    }
}
void solve()
{
    ll i,j,k,q;
    char c;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        add(i,a[i-1]);
    }
    cin>>q;
    while(q--)
    {
        cin>>c;
        if(c=='u')
        {
            cin>>i>>j;
            add(i,j);
        }
        else
        {
            cin>>i>>j;
            cout<<sum(j)-sum(i-1)<<"\n";
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
