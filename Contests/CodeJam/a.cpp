#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,tt;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        ll i,j,k,n;
        cin>>n;
        vector<pair<ll,ll>>a;
        for(i=0;i<n;i++)
        {
            cin>>j>>k;
            a.push_back({j,k});
        }
        sort(a.begin(),a.end());
        unordered_map<ll,ll>c;
        unordered_map<ll,vector<ll>>d;
	vector<ll>e(n,0);
	bool f=true;
	ll p,q;
	p=q=0;
	for(i=0;i<n && f;i++)
	{
		if(a[i].first>=p)
		{
			e[i]=1;
			p=a[i].second;
		}
		else if(a[i].first>=q)
		{
			e[i]=2;
			q=a[i].second;
		}
		else
			f=false;
	}
        cout<<"Case #"<<tt<<": ";
	if(f)
	{
		for(i=0;i<n;i++)
		{
			if(e[i]==1)
				cout<<"C";
			else
				cout<<"J";
		}
	}
	else
		cout<<"IMPOSSIBLE";
        cout<<"\n";
    }
}
