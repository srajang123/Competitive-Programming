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
vector<ll>t(4*N);
ll n;
//f=0 or
//f=1 xor
ll build(vector<ll>&a,ll v,ll tl,ll tr)
{
    ll f=0;
    if(tl==tr)
    {
        t[v]=a[tl];
        f=0;
    }
    else
    {
        ll tm=(tl+tr)/2;
        f=build(a,2*v,tl,tm);
        f&=build(a,2*v+1,tm+1,tr);
        if(f==0)
            t[v]=t[v*2]|t[v*2+1];
        else
            t[v]=t[v*2]^t[v*2+1];
        f=(f==0);
    }
    return f;
}
ll sum(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 0;
    else if(l==tl && r==tr)
        return t[v];
    ll tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}
ll update(ll v,ll tl,ll tr,ll p,ll val)
{
    ll f=0;
    if(tl==tr)
    {
        t[v]=val;
        f=0;
    }
    else
    {
        ll tm=(tl+tr)/2;
        if(p<=tm)
            f=update(2*v,tl,tm,p,val);
        else
            f=update(2*v+1,tm+1,tr,p,val);
        if(f==0)
            t[v]=t[2*v]|t[2*v+1];
        else
            t[v]=t[2*v]^t[2*v+1];
        f=(f==0);
    }
    return f;
}
void solve()
{    
    ll q,i,j,k,l,m;
    cin>>n>>q;
    n=pow(2,n);
    vector<ll>a(n+1);
    for(i=0;i<n;i++)
    {
        cin>>j;
        a[i]=j;
    }
    build(a,1,0,n-1);
    while(q--)
    {
        cin>>i>>j;
        {
            i--;
            update(1,0,n-1,i,j);
            cout<<t[1]<<"\n";
        }
    }
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
