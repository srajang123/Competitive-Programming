#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
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
ll length(ll a,ll b, ll n)
{
	ll c=0;
	ll i;
	for(i=3;i<=n;i++)
	{
		c=a+2*b;
		a=b;
		b=c;
	}
	return c;
}
void solve()
{
	ll n,i,j,k;
	string a,b,c;
	cin>>n>>a>>b>>k;
	if(length(a.size(),b.size(),n)>k)
	{		
		cout<<"-1";
		return;
	}
	for(i=3;i<=n;i++)
	{
		c="";
		c.append(a);
		c.append(b);
		c.append(b);
		a=b;
		b=c;
	}
	cout<<c<<"\n";
	if(c.size()<k)
		cout<<"-1";
	else
	{
		cout<<c[k-1];
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
