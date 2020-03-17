#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
	ll i,j,k,n,c=0;
	cin>>n;
	if(n>250000)
	{
		j=250000;
		k=500000-j;
		if(n<500000)
			k=n-j;
		c+=0.05*k;
	}
	if(n>500000)
	{
		j=500000;
		k=750000-j;
		if(n<750000)
			k=n-j;
		c+=0.1*k;
	}
	if(n>750000)
	{
		j=750000;
		k=1000000-j;
		if(n<1000000)
			k=n-j;
		c+=.15*k;
	}
	if(n>1000000)
	{
		j=1000000;
		k=1250000-j;
		if(n<1250000)
			k=n-j;
		c+=0.2*k;
	}
	if(n>1250000)
	{
		j=1250000;
		k=1500000-j;
		if(n<1500000)
			k=n-j;
		c+=0.25*k;
	}
	if(n>1500000)
	{
		j=1500000;
		k=n-j;
		c+=0.3*k;
	}
	n-=c;
	cout<<n<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
