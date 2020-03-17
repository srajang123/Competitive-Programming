#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 1000000007

ll knap(ll W,vector<ll>a,vector<ll>b,ll n)
{/*
	ll i,w;
	unordered_map<pair<ll,ll>,pair<ll,vector<ll>>>K;
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0||w==0)
				K[{i,w}].first=0;
			else if(a[i-1]<=w)
				{
					K[{i,w}].second=K[{i-1,w}].second;
					if(b[i-1]+K[{i-1,w-a[i-1]}].first>K[{i-1,w}].first)
					{
						K[{i,w}].second.push_back(b[i-1]);
					}
				}
			else
				K[{i,w}]=K[{i-1,w}];
		}
	}
	return K[{i,w}];*/
	ll i,w;
	vector<vector<ll>>K(n+1,vector<ll>(W+1));
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)	
				K[i][w]=0;
			else if(a[i-1]<=w)
				K[i][w]=max(b[i-1]+K[i-1][w-a[i-1]],K[i-1][w]);
			else
				K[i][w]=K[i-1][w];
		}
	}/*
	vector<ll>ans;
	ll r=K[n][W];
	for(i=n;i>0 && r>0;i--)
	{
		if(r==K[i-1][W])
			continue;
		else
		{
			ans.push_back(b[i-1]);
			r-=b[i-1];
			w=w-a[i-1];
		}
	}*/
	return K[n][W];

}
void solve()
{
	ll i,j,k,n,w,x,y;
	cin>>n>>w>>x>>y;
	vector<ll>a(n),b(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	ll mx=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			vector<ll>xx=b;
			if(xx[i]>=xx[j])
			{
				xx[i]*=x>y?x:y;
				xx[j]*=x>y?y:x;
			}
			else
			{
				xx[i]*=x>y?y:x;
				xx[j]*=x>y?x:y;
			}
			k=knap(w,a,xx,n);
			mx=mx>k?mx:k;
		}
	}
	cout<<mx<<"\n";
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
