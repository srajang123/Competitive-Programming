#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100001
vector<ll>prime(N);
void sieve()
{
	ll i,j,k;
	prime[1]=1;
	for(i=2;i<N;i++)
		prime[i]=i;
	for(i=4;i<N;i+=2)
		prime[i]=2;
	for(i=3;i*i<=N;i++)
	{
		if(prime[i]==i)
		{
			for(j=i*i;j<=N;j+=i)
			{
				if(prime[j]=j)
					prime[j]=i;
			}
		}
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
vector<ll> getFactors(ll x)
{
	vector<ll>r;
	x=abs(x);
	while(x!=1)
	{
		r.push_back(prime[x]);
		x/=prime[x];
	}
	return r;
}
vector<ll>Divs(unordered_map<ll,ll>ff)
{
	vector<ll>div;
	ll f=1;
	for(auto x:ff)
	{
		f*=1+x.second;
	}
	div.resize(f);
	div[0]=1;
	f=1;
	for(auto x:ff)
	{
		ll cf=f;
		ll m=1;
		for(ll j=0;j<x.second;j++)
		{
			m*=x.first;
			for(ll k=0;k<cf;k++)
			{
				div[f++]=div[k]*m;
			}
		}
	}
	return div;
}
void solve()
{
	ll n,m,i,j,k,l,c=0;
	cin>>n>>m;
	vector<ll>x(n),y(m);
	unordered_map<ll,ll>cc,dd,xx,yy;
	for(i=0;i<n;i++)
		{
			cin>>x[i];
			if(x[i]==0)
			{
				c=m*(n-1);
			}
			xx[x[i]]++;
		}
	for(i=0;i<m;i++)
		{
			cin>>y[i];
			if(y[i]==0)
			{
				c=n*(m-1);
			}
			yy[y[i]]++;
		}
	for(i=0;i<n;i++)
	{
		unordered_map<ll,ll>ff;
		for(auto x:getFactors(x[i]))
		{
			ff[x]+=2;
		}
		vector<ll>div=Divs(ff);
		sort(div.begin(),div.end());
		ll s,e;
		s=0;
		e=div.size()-1;
		while(s<=e)
		{
			if((yy[-div[s]]!=0 && yy[div[e]]!=0)||(yy[div[s]]!=0 && yy[-div[e]]!=0))
				c++;
			s++;
			e--;
		}
	}
	for(i=0;i<m;i++)
	{
		unordered_map<ll,ll>ff;
		for(auto xg:getFactors(y[i]))
		{
			ff[xg]+=2;
		}
		vector<ll>div=Divs(ff);
		sort(div.begin(),div.end());
		ll s,e;
		s=0;
		e=div.size()-1;
		while(s<=e)
		{
			if((xx[-div[s]]!=0 &&xx[div[e]]!=0)||(xx[div[s]]!=0 &&xx[-div[e]]!=0))
				c++;
			s++;
			e--;
		}
	}
	cout<<c<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
	sieve();
    while(t--)
    {
        solve();
    }
}
