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
	ll n,k,i,j=0,l=0,m;
	cin>>n>>k;
	vector<ll>a(n),b(n,0),c(n,0);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<n;i++)
		a[i]+=a[i-1];
	l=j=0;
	double ss=0.0,t=0.0;
	a.insert(a.begin(),0);
	/*for(auto x:a)
		cout<<x<<",";*/
	for(k;k<=n;k++)
	{
		for(i=k;i<=n;i++)
		{
			j=a[i]-a[i-k];
			ss=(j*1.0)/(k);
			t=t>ss?t:ss;
			ss=t;
			//cout<<j<<"|"<<ss<<"|";
		}
	}
	ss=t;
	cout<<fixed<<showpoint;
	cout<<setprecision(15)<<ss;
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
