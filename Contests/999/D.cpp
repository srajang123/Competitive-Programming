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
	ll n,m,i,j,k,l,c=0;
	cin>>n>>m;
	vector<pair<ll,ll>>a(n);
	vector<ll>b(m,0),ee(n);
	for(i=0;i<n;i++)
	{
		cin>>j;
		ee[i]=j;
		j%=m;
		b[j]++;
		a[i]={j,i};
	}
	sort(a.begin(),a.end());
	for(auto x:a)
		cout<<x.first<<" ";
	for(i=0;i<n;i++)
	{
		if(b[a[i].first]==n/m)
			i+=n/m-1;
	}
	cout<<"\n";
	for(i=m-1;i>0;i--)
	{
		if(b[i]!=n/m)
		{
			j=abs(n/m-b[i]);
			b[i-1]-=j;
			c+=j;
		}
		cout<<b[i]<<":";
	}
	cout<<c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
}
