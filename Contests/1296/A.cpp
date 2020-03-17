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
	ll i,j,k,n,s=0;
	cin>>n;
	vector<ll>a,b;
	for(i=0;i<n;i++)
	{
		cin>>j;
		if(j%2==0)
			a.push_back(j);
		else
		{
			b.push_back(j);
		}
		s+=j;
	}
	if(s%2!=0 || (a.size()>0 && b.size()>0))
		cout<<"YES\n";
	else
	{
		cout<<"NO\n";
	}
	
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
