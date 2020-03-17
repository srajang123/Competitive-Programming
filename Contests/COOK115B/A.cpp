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
	ll n,i,j,k;
	string s;
	cin>>n>>s;
	ll a=0,b=0,p=0,q=0;
	k=2*n;
	for(i=0;i<2*n;i++)
	{
		if(i%2==0)
		{
			if(s[i]=='1')
				a++;
			p++;
		}
		else
		{
			if(s[i]=='1')
				b++;
			q++;
		}
		if(a+n-p<b ||b+n-q<a)
		{
			k=i+1;
			break;
		}
	}
	cout<<k<<"\n";
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
