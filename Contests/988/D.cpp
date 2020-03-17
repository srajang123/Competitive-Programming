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
bool ispow(ll a)
{
	if(pow(2,log2(a))==a)
		return true;
	return false;
}
void solve()
{
	ll i,j,k,n;
	cin>>n;
	vector<ll>a(n);
	map<ll,vector<ll>>b;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		for(auto x:b)
		{
			if(ispow(abs(x.first-a[i])))
				b[x.first].push_back(a[i]);
		}
		b[a[i]].push_back(a[i]);
	}
	k=0;
	for(auto x:b)
		k=k>x.second.size()?k:x.second.size();
	for(auto x:b)
	{
		if(x.second.size()==k)
		{
			cout<<k<<"\n";
			for(i=0;i<x.second.size();i++)
			{
				cout<<x.second[i]<<" ";
			}
			break;
		}
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
