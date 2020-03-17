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
	ll n,m,c,i,j,d=0;
	cin>>n>>m>>c;
	double k,l;
	vector<double>a(c);
	for(i=0;i<c;i++)
		cin>>a[i];
	ll p=0,q=0;
	sort(a.rbegin(),a.rend());
	k=0;
	for(i=0;i<c && k<n;i++)
	{
		k+=2*a[i];
		p++;
	}
	if(k<n)
		p=-1;
	k=m/(2.0)+a[0];
	if(k>=m)
		p=1;
	k=0;
	for(i=0;i<c && k<m;i++)
	{
		k+=2*a[i];
		q++;
	}
	if(k<m)
		q=-1;
	k=n/(2.0)+a[0];
	if(k>=n)
		q=1;
	if(p<0 && q<0)
		d=-1;
	else if(p>=0 && q<0)
		d=p;
	else if(p<0 && q>=0)
		d=q;
	else
	{
		d=p>q?q:p;
	}
	cout<<d<<"\n";
	
	
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
