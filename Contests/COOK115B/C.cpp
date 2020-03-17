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
	ll i,j,k,l,n;
	cin>>n;
	vector<ll>a(n),b(n);
	bool f=false;
	//vector<pair<ll,ll>>p,q;
	unordered_map<ll,ll>x,y,p;
	set<ll>z,zz;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		//p.push_back({a[i],i});
		//x[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		p[b[i]]++;
		//q.push_back({b[i],i});
		y[b[i]]++;
	}
	if(n==1)
		{
			cout<<b[0]<<"\n";
			return;
		}
	for(i=0;i<n;i++)
	{
		j=a[0];
		k=b[i];
		j=j^k;
		z.insert(j);
	}
	for(i=0;i<n;i++)
	{
		j=a[1];
		k=b[i];
		j=j^k;
		zz.insert(j);
	}
	for(auto u:z)
		x[u]++;
	for(auto u:zz)
		x[u]++;
	zz.clear();
	for(i=0;i<n;i++)
	{
		j=a[2];
		k=b[i];
		j=j^k;
		zz.insert(j);
	}
	vector<ll>t;
	for(auto u:x)
	{
		if(u.second>=2)
		{
			t.push_back(u.first);
		}
	}
	vector<ll>o;
	ll cc=1000000/n;

	for(auto u:t)
	{
		cc--;
		unordered_map<ll,ll>q(p.begin(),p.end());
		o.clear();
		l=n;
		for(i=0;i<n;i++)
		{
			j=u^a[i];
			if(q[j]<=0)
				break;
			q[j]--;
			o.push_back(j);
			l--;
		}
		if(l==0 && i>=n)
			{
				f=true;
				break;
			}
		if(cc<=0)break;
	}
	if(!f)
		cout<<-1;
	else
	{
		for(auto u:o)
			cout<<u<<" ";
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
