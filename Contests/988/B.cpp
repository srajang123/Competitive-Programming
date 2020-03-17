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
bool isSubstr(string a,string b)
{
	if(b.find(a)!=string::npos)
		return true;
	return false;
}
void solve()
{
	ll n,i,j,k;
	cin>>n;
	vector<string>a(n);
	vector<pair<ll,string>>b(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]={a[i].size(),a[i]};
	}
	sort(b.begin(),b.end());
	ll c=0;
	for(i=0;i<n;i++)
		b[i].first=INT64_MAX;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(isSubstr(b[i].second,b[j].second))
			{
				b[i].first=j;
				c++;
				break;
			}
			
		}
	}
	sort(b.begin(),b.end());
	c=0;
	for(i=0;i<n-1;i++)
	{
		if(isSubstr(b[i].second,b[i+1].second))
			c++;
	}
	if(c==n-1)
	{
		cout<<"YES\n";
		for(auto x:b)
			cout<<x.second<<"\n";
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
