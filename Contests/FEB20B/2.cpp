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
void solve()
{
	ll i,j,k,n,p,q;
	cin>>n>>k;
	vector<ll>a(n),b(n,0),c(n,0),d(n,0);
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)
	{
		c[i]=(k-a[i]%k)%k;
		b[i]=a[i]%k;
		d[i]=(a[i]-c[i])/k;
	}
	b.insert(b.begin(),0);
	c.push_back(0);
	for(i=1;i<c.size();i++)
		b[i]+=b[i-1];
	for(i=d.size()-2;i>=0;i--)
		c[i]+=c[i+1];
	/*
	for(i=1;i<n;i++)
	{
		b[i]+=b[i-1];
		c[i]+=c[i-1];
		d[i]+=d[i-1];
	}
	//b.insert(b.begin(),0);
	/*c.push_back(0);
	d.push_back(0);
	reverse(c.begin(),c.end());
	reverse(d.begin(),d.end());
	/*c.push_back(0);
	d.push_back(0);
	for(auto x:b)
		cout<<x<<" ";
	cout<<"\n";
	for(auto x:c)
		cout<<x<<" ";
	cout<<"\n";
	for(auto x:d)
		cout<<x<<" ";*/
	ll mn=INT64_MAX,l;
	for(i=0;i<=n;i++)
	{
		l=b[i]-c[i];
		if(l>=0)
		{
			mn=mn<l?mn:l;
		}
		else
		{
			ll z=ceil((abs(l)*1.0)/k);
			if(z>=d[i])
			{
				l+=k*d[i];
				if(l>=0)
				{
					mn=mn<l?mn:l;
				}
			}
		}
		//cout<<l<<",";
	}
	//cout<<"\n";
	cout<<mn<<"\n";
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
