#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
#define ll long long
int prime
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
	ll t;
	ll i,j,k,a,b,c=0,mn=INT64_MAX,mx=0;
	cin>>t;
	vector<pair<ll,ll>>p(t);
	for(i=0;i<t;i++)
	{
		cin>>a>>b;
		p[i]={min(a,b),max(a,b)};
		mn=mn>min(a,b)?min(a,b):mn;
		mx=mx<max(a,b)?max(a,b):mx;
		if(b<a)
		{
			k=a;
			a=b;
			b=k;
		}
		if(a%2==1)
			a++;
		k=(b-a)/2+1;
		cout<<k<<"\n";
	}/*
	vector<ll>q(mx-mn+1,0);
	for(i=mn;i<=mx;i++)
	{
		k=0;
		for(j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				k++;
				if(i/j!=j)
					k++;
			}
		}
		if(k%2==0)
			q[i-mn]=1;
	}
	for(i=0;i<t;i++)
	{
		c=0;
		for(j=p[i].first;j<=p[i].second;j++)
		{
			if(q[j-mn]==1)
				c++;
		}
		cout<<c<<"\n";
	}*/
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
