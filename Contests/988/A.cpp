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
	ll n,k,i,j,l;
	cin>>n>>k;
	vector<ll>a(n);
	set<ll>b;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b.insert(a[i]);
	}
	if(b.size()>=k)
	{
		cout<<"YES\n";
		l=0;
		for(auto x:b)
		{
			l++;
			if(l>k)break;
			for(i=0;i<n;i++)
			{
				if(a[i]==x)
				{
					cout<<(i+1)<<" ";
					break;
				}
			}
		}
	}
	else
	{
		cout<<"NO";
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
