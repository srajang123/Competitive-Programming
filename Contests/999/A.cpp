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
	ll n,k,i,j,l=0,r=0,c=0;
	bool s=true;
	cin>>n>>k;
	vector<ll>a(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(s && a.size()>0)
	{
		l=r=0;
		for(i=0;i<a.size();i++)
		{
			if(a[i]<=k)
				l++;
			else
			{
				break;
			}
			
		}
		for(i=a.size()-1;i>=0;i--)
		{
			if(a[i]<=k)
				r++;
			else
			{
				break;
			}
			
		}
		if(l==r && l==0)
			s=false;
		else
		{
			c++;
		}
		if(l>=r)
		{
			a.erase(a.begin());
		}
		else
			a.pop_back();
	}
	cout<<c;
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
