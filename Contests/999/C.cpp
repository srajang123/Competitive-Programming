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
	string s;
	cin>>n>>k>>s;
	vector<vector<ll>>a(26);
	vector<ll>b(n,0);
	for(i=0;i<n;i++)
	{
		a[s[i]-'a'].push_back(i);
	}
	l=0;
	for(i=0;i<26 && l<k;i++)
	{
		for(auto x:a[i])
		{
			l++;
			b[x]=1;
			if(l==k)break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(b[i]!=1)
			cout<<s[i];
	}

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
