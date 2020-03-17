#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power( ll a,ll b)
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
	ll i,j,k,n,c=0;
	cin>>n;
	vector<ll>a(n),b(n);
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(i=0;i<n;i++)
	{
		c+=min(a[i],b[i]);
	}
	cout<<c<<"\n";
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
