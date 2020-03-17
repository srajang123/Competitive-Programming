#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
#define ll long long

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

void solve()
{
	ll n,q,i,j,k,l,s;
	cin>>n>>q;
	vector<ll>a(18,0);
	for(i=0;i<n;i++)
	{
		cin>>j;
		a[log2(j)]++;
	}
	for(i=0;i<q;i++)
	{
		cin>>j;
		ll c=0;
		k=log2(j);
		s=j;
		for(l=k;l>=0 && s>0;l--)
		{
			ll u=s/pow(2,l);
			if(a[l]>=u)
			{
				ll t=pow(2,l);
				s=s%t;
				c+=u;
			}
			else if(a[l]>0)
			{
				s=s-a[l]*pow(2,l);
				c+=a[l];
			}
		}
		if(s!=0)
			c=-1;
		cout<<c<<"\n";
	}
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
