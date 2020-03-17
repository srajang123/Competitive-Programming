#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
#define ll long long
#define N 1000000000
vector<bool>prime(N+1,true);
vector<ll>b(N+1,0);
ll lllll=0;
void sieve(){
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
	for(i=2;i<=N;i++)
	{
		if(prime[i])
			lllll=i;
	}
}
ll pow(ll a,ll b)
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
ll pow(ll a,ll b,ll m)
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

void solve()
{
	ll i,j,k,n,s=0,e,md;
	cin>>n;
	vector<ll>a(n),c(n,0);
	set<pair<ll,ll>>aa;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		c[i]=b[a[i]]-a[i];
		aa.insert({c[i],i+1});
	}
	for(auto x:aa)
		cout<<x.second<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
	sieve();
	for(ll i=lllll;i>=0;i--)
	{
		if(prime[i])
			b[i]=i;
		else
			b[i]=b[i+1];
	}
    while(t--)
    {
        solve();
    }
}
