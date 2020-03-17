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
ll time(string s)
{
	ll h,m,st,i,j;
	h=(s[0]-48)*10+s[1]-48;
	m=(s[3]-48)*10+s[4]-48;
	st=(s[6]-48)*10+s[7]-48;
	return h*60*60+m*60+st;
}
void solve()
{
	ll n,i,j,k,l,p,q;
	cin>>n;
	map<ll,vector<ll>>cc;
	map<ll,ll>dd;
	string s,r;
	vector<string>a(n);
	vector<ll>b(n),c(n),d(n),ee(n,1);
	vector<pair<ll,pair<ll,ll>>>h(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		cin>>s;
		c[i]=time(s);
		cin>>s>>r;
		d[i]=time(s)+time(r);
		h[i]={c[i],{d[i],b[i]}};
	}
	sort(h.begin(),h.end());
	dd[1]=h[0].second.first;
	for(i=1;i<n;i++)
	{
		ee[i]=dd.size()+1;
		for(auto tt:dd)
		{
			if(tt.second<h[i].first)
			{
				ee[i]=tt.first;
				break;
			}
		}
		dd[ee[i]]=h[i].second.first;
	}
	map<ll,ll>uu;
	for(i=0;i<n;i++)
	{
		uu[h[i].second.second]=ee[i];
	}
	cout<<dd.size()<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" "<<b[i]<<" "<<uu[b[i]]<<"\n";
	}

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
