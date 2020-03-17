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
	ll i,j,k,l,n;
	string s;
	map<pair<ll,ll>,vector<ll>>a;
	cin>>n>>s;
	ll x=0,y=0;
	a[{0,0}].push_back(0);
	for(i=0;i<n;i++)
	{
		switch(s[i])
		{
			case 'L':x--;
					break;
			case 'R':x++;
					break;
			case 'U':y++;
					break;
			case 'D':y--;
					break;
		}
		a[{x,y}].push_back(i+1);
	}
	ll mx=INT64_MAX;
	for(auto u:a)
	{
		for(i=0;i<u.second.size()-1;i++)
		{
			if(u.second[i+1]-u.second[i]+1<mx)
			{
				mx=u.second[i+1]-u.second[i]+1;
				x=u.second[i];
				y=u.second[i+1];
			}
		}
	}
	if(mx==INT64_MAX)
		cout<<"-1";
	else
	{
		cout<<(x+1)<<" "<<y;
	}
	cout<<"\n";
	
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
