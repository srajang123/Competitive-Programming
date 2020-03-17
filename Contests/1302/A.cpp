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
	ll n,m,i,j,k;
	cin>>n>>m;
	vector<vector<ll>>a(n,vector<ll>(m));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}
	ll p=0,q=0,r=0;
	for(i=0;i<n && r==0;i++)
	{
		for(j=0;j<m && r==0;j++)
		{
			if(a[i][j]>a[0][j] && a[i][j]<a[i][0])
			{
				p=i+1;
				q=j+1;
				r=1;
			}
		}
	}
	cout<<p<<" "<<q;
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
