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
	ll i,j,k,n,s=0,t=0;
	cin>>k;
	vector<vector<ll>>a(k);
	unordered_map<ll,vector<ll>>xx;
	unordered_set<ll>chk;
	unordered_set<ll>b;
	for(i=0;i<k;i++)
	{
		cin>>n;
		ll u;
		s=0;
		for(u=0;u<n;u++)
		{
			cin>>j;
			a[i].push_back(j);
			s+=j;
		}
		for(u=0;u<n;u++)
		{
			b.insert(s-a[i][u]);
		}
		for(auto x:b)
		{
			//cout<<x<<",";
			xx[x].push_back(i);
			if(xx[x].size()>1)
				chk.insert(x);
		}
		b.clear();
	}
	if(chk.size()>0)
	{
		cout<<"YES\n";
		for(auto x:chk)
		{
			i=xx[x][0];
			s=0;
			for(j=0;j<a[i].size();j++)
				s+=a[i][j];
			for(j=0;j<a[i].size();j++)
			{
				if(s-a[i][j]==x)
				{
					cout<<(i+1)<<" "<<(j+1)<<"\n";
					break;
				}
			}
			i=xx[x][1];
			s=0;
			for(j=0;j<a[i].size();j++)
				s+=a[i][j];
			for(j=0;j<a[i].size();j++)
			{
				if(s-a[i][j]==x)
				{
					cout<<(i+1)<<" "<<(j+1)<<"\n";
					break;
				}
			}
			break;
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
