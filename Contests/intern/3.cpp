#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 1000000007

ll c=0;
//Main Solution
vector<vector<ll>>d(1010,vector<ll>(1010,-1));
ll rec(ll n,ll l,ll k)
{
	if(n==0)
	{
		return 1;
	}
	if(n<0)
		return 0;
	if(d[n][l]!=-1)	return d[n][l];
	ll z=0;
	ll j=2;
	while(j<=k)
	{
		z=(z+rec(n-j,j,k))%M;
		j+=2;
	}
	d[n][l]=z;
	return d[n][l];
}
void solve()
{
	ll n,l,i,j,k,m;
	cin>>n>>l;
	k=0;
	if(n%2==1)
	{
		cout<<0<<"\n";
		return;
	}
	for(i=0;i<d.size();i++)
	{
		for(j=0;j<d[i].size();j++)
			d[i][j]=-1;
	}
	j=l;
	c=0;
	j=2;
	while(j<=l)
	{
		k=(k+rec(n-j,j,l))%M;
		j+=2;
	}
	cout<<k<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
