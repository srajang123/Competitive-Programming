#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a,ll b)
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
ll power(ll a,ll b,ll m)
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
bool usort(pair<ll,ll>a,pair<ll,ll>b)
{
	if(a.second<=b.second)
		return true;
	return false;
}
ll solve()
{
	ll n,i,j,k,l,t;
	char s;
	cin>>n;
	vector<vector<ll>>a(4,vector<ll>(4,0));
	for(i=0;i<n;i++)
	{
		cin>>s>>j;
		t=s-65;
		switch(j)
		{
			case 12: j=0;
					break;
			case 3: j=1;
					break;
			case 6: j=2;
					break;
			case 9: j=3;
					break;
		}
		a[t][j]++;
	}
	/*
	vector<vector<pair<ll,ll>>>b;
	for(i=0;i<4;i++)
	{
		vector<pair<ll,ll>>c;
		for(j=0;j<4;j++)
		{
			c.push_back({j,a[i][j]});
		}
		sort(c.begin(),c.end(),usort);
		b.push_back(c);
	}*/
	ll mx=INT64_MIN;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(j==i)continue;
			for(k=0;k<4;k++)
			{
				if(k==j || k==i)continue;
				for(l=0;l<4;l++)
				{
					if(l==i || l==j||l==k)continue;
					vector<ll>cc;
					cc.push_back(a[0][i]);
					cc.push_back(a[1][j]);
					cc.push_back(a[2][k]);
					cc.push_back(a[3][l]);
					sort(cc.rbegin(),cc.rend());
					ll c=0;
					c=cc[0]*100+cc[1]*75+cc[2]*50+cc[3]*25;
					for(ll m=0;m<4;m++)
					{
						if(cc[m]==0)
							c-=100;
					}
					//cout<<cc[0]<<":"<<cc[1]<<":"<<cc[2]<<":"<<cc[3]<<"=>"<<c<<"\n";
					/*
					for(ll m=0;m<4;m++)
					{
						if(m!=i)
							c-=100;
					}
					for(ll m=0;m<4;m++)
					{
						if(m!=j)
							c-=100;
					}
					for(ll m=0;m<4;m++)
					{
						if(m!=k)
							c-=100;
					}
					for(ll m=0;m<4;m++)
					{
						if(m!=l)
							c-=100;
					}*/
					mx=mx>c?mx:c;
				}
			}
		}
	}
	cout<<mx<<"\n";
	return mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,s=0;
    cin>>t;
    while(t--)
    {
        s+=solve();
    }
	cout<<s;
}
