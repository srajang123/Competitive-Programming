#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
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
int dow(int y, int m, int d)
{
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
vector<ll>xxx(401,0);
void solve()
{
	ll i,j,k,n=2,p,q,a,b,c=0;
	cin>>p>>q>>a>>b;
	if(p>2)
		q++;
	if(a<2)
		b--;
	ll l,r;
	l=(q-1)/400;
	l=l*xxx.back()+xxx[(q-1)%400];
	r=(b)/400;
	r=r*xxx.back()+xxx[(b)%400];/*
	for(i=q;i<=b;i++)
	{
		if(i%400==0 ||(i%4==0 && i%100!=0))
		{
			if(dow(i,2,7)==5)
				c++;
		} 
		else
		{
			if((dow(i,2,7)==5||dow(i,2,6)==5))
				c++;
		}
		
	}*/
	c=r-l;
	cout<<c<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
	ll i,j;
	for(i=1;i<=400;i++)
	{
		if(i%400==0 ||(i%4==0 && i%100!=0))
		{
			if(dow(i,2,7)==5)
				xxx[i]++;
		} 
		else
		{
			if((dow(i,2,7)==5||dow(i,2,6)==5))
				xxx[i]++;
		}
	}
	for(i=1;i<=400;i++)
		xxx[i]+=xxx[i-1];
    while(t--)
    {
        solve();
    }
}
