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
	ll n,i,j,k,c;
	string s;
	cin>>n>>s;
	vector<ll>a;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a.push_back(i);
			if(i!=n/i)
				a.push_back(n/i);
		}
	}
	sort(a.begin(),a.end());
	string t="";
	for(i=0;i<a.size();i++)
	{
		for(j=a[i]-1;j>=0;j--)
		{
			t.push_back(s[j]);
		}
		for(j=a[i];j<n;j++)
			t.push_back(s[j]);
		s=t;
		t.clear();
		//cout<<s<<"\n";
	}
	cout<<s;
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
