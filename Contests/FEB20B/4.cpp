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
	ll n,p,i,j,k,c=0;
	cin>>n>>p;
	vector<ll>d(n),a(n,0),b(n,0);
	for(i=0;i<n;i++)
		cin>>d[i];
	bool f=false;
	for(i=0;i<n && !f;i++)
	{
		if(p%d[i]!=0)
		{
			a[i]=ceil((1.0*p)/d[i]);
			f=true;
		}
	}
	if(!f)
	{
		vector<pair<ll,ll>>x;
		for(i=0;i<n;i++)
		{
			x.push_back({d[i],i});
		}
		sort(x.begin(),x.end());
		for(i=0;i<n-1 && !f;i++)
		{
			k=p;
			k-=x[i+1].first;
			j=ceil((k*1.0)/x[i].first);
			if((((j-1)*x[i].first+x[i+1].first<p)||(j*x[i].first<p))&&(x[i+1].first+j*x[i].first>p))
			{
				f=true;
				a[i]=j;
				a[i+1]=1;
			}
		}
	}
	if(f)
	{
		cout<<"YES ";
		for(auto z:a)
			cout<<z<<" ";
	}
	else
	{
		cout<<"NO";
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
