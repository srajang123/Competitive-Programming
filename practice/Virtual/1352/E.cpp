#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
	ll i,j,k,l,m,n;
	cin>>n;
	vector<ll>a(n),b(n+1,0);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	l=0;
	for(i=0;i<n;i++)
	{
		k=a[i];
		for(j=i+1;j<n;j++)
		{
			k+=a[j];
			if(k<=n)
				b[k]++;
		}
	}
	for(i=0;i<n;i++)
		l+=b[a[i]]>0?1:0;
	cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
