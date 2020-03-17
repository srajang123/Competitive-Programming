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
set<ll>xxx;
void DFS(ll v,vector<ll>b,vector<vector<ll>>a)
{
	b[v]=1;
	xxx.insert(v);
	for(ll i=0;i<a[v].size();i++)
	{
		if(a[v][i]==1)
		{
			if(b[i]!=1)
			{
				DFS(i,b,a);
			}
		}
	}
}
void solve()
{
	ll n,m,s,i,j,k,c=0;
	cin>>n>>m>>s;
	vector<vector<ll>>a(n);
	vector<ll>b(n,0);
	vector<set<ll>>t;
	for(i=0;i<m;i++)
	{
		//a[i][i]=1;
		cin>>j>>k;
		a[j-1].push_back(k-1);
	}
	s--;
	for(i=0;i<n;i++)
	{
		DFS(i,b,a);
		t.push_back(xxx);
		xxx.clear();
	}
	/*
	for(i=0;i<xxx.size();i++)
	{
		b[xxx[i]]=1;
		cout<<xxx[i]<<":";
	}*/
	for(auto x:xxx)
		cout<<x<<",";
	cout<<n;
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
