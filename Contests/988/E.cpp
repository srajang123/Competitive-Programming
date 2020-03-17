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

void solve()
{
	ll i,j,k,n;
	ll a=-1,b=-1,c=-1,d=-1,e=-1,ans=INT64_MAX;
	string s;
	cin>>s;
	n=s.size();
	string t;
	i=n-1;
	while(i>=0)
	{
		if(s[i]=='0')
		{
			if(a==-1)
				a=max(i,a);
			else
			{
				b=max(i,b);
			}
			
		}
		else if(s[i]=='2')
		{
			c=max(i,c);
		}
		else if(s[i]=='5')
		{
			d=max(i,d);
		}
		else if(s[i]=='7')
		{
			e=max(i,e);
		}
		i--;
	}
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e;
	
	ll pp=INT64_MAX,qq=INT64_MAX,rr=INT64_MAX,ss=INT64_MAX;
	k=s.size()-1;
	if(a>=0 && b>=0)
	{
		//pp=(k-max(a,b))+(k-1-min(a,b));
		// 00
			char xx;
			ss=0;
			t=s;
			for(i=a;i<n-1;i++)
			{
				ss++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=n-2;
			while(i>=0)
			{
				if(t[i]=='0')
				{
					c=i;
					break;
				}
				i--;
			}
			for(i=c;i<n-2;i++)
			{
				ss++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=0;
			ll z=0;
			while(i<n-2)
			{
				if(t[i]!='0')break;
				z++;
				i++;
			}
			if(z==n-2 && z!=0)
				ss=INT64_MAX;
			else
			{
				ss+=z;
			}
			
	}
	
	if(c>=0 && d>=0)
		{
			//qq=(k-d)+(k-1-c);
			//25
			char xx;
			pp=0;
			t=s;
			//cout<<c<<":"<<d;
			for(i=d;i<n-1;i++)
			{
				pp++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=n-2;
			while(i>=0)
			{
				if(t[i]=='2')
				{
					c=i;
					break;
				}
				i--;
			}
			for(i=c;i<n-2;i++)
			{
				pp++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=0;
			ll z=0;
			while(i<n-2)
			{
				if(t[i]!='0')break;
				z++;
				i++;
			}
			if(z==n-2 && z!=0)
				pp=INT64_MAX;
			else
			{
				pp+=z;
			}
		}
	if(a>=0 && d>=0)
		{
			//rr=(k-a)+(k-1-d);
			//50
			char xx;
			qq=0;
			t=s;
			for(i=a;i<n-1;i++)
			{
				qq++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=n-2;
			while(i>=0)
			{
				if(t[i]=='5')
				{
					c=i;
					break;
				}
				i--;
			}
			for(i=c;i<n-2;i++)
			{
				qq++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=0;
			ll z=0;
			while(i<n-2)
			{
				if(t[i]!='0')break;
				z++;
				i++;
			}
			if(z==n-2 && z!=0)
				qq=INT64_MAX;
			else
			{
				qq+=z;
			}
		}
	if(d>=0 && e>=0)
		{
			//ss=(k-d)+(k-1-e);
			//75
			char xx;
			rr=0;
			t=s;
			for(i=d;i<n-1;i++)
			{
				rr++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=n-2;
			while(i>=0)
			{
				if(t[i]=='7')
				{
					c=i;
					break;
				}
				i--;
			}
			for(i=c;i<n-2;i++)
			{
				rr++;
				xx=t[i];
				t[i]=t[i+1];
				t[i+1]=xx;
			}
			i=0;
			ll z=0;
			//cout<<t<<")";
			while(i<n-2)
			{
				if(t[i]!='0')break;
				z++;
				i++;
			}
			//cout<<z<<"=>"<<rr<<"\n";
			if(z==n-2 && z!=0)
				rr=INT64_MAX;
			else
			{
				rr+=z;
			}
		}
	//cout<<pp<<" "<<qq<<" "<<rr<<" "<<ss<<"\n";
	a=min(pp,min(qq,min(rr,ss)));
	if(a==INT64_MAX)
		a=-1;
	cout<<a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
}
