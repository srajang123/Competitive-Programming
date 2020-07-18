#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 1000000007

/*
	*********************************************************************
	*                             Code By                               *
	*                                                                   *
	*                            Srajan Gupta                           *
	*                            srajang_123                            *
	*                                                                   *
	*********************************************************************
*/
//Prime Numbers

vector<bool>prime(N+1,true);
void sieve()
{
	ll i,j,k;
	prime[0]=prime[1]=false;
	for(i=2;i*i<=N;i++)
	{
		if(prime[i])
		{
			for(j=i*i;j<=N;j+=i)
			{
				prime[j]=false;
			}
		}
	}
}

//Exponentiation

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

//Prime Factors

vector<ll> factors(ll n)
{
	vector<ll>r;
	ll i,j;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			r.push_back(i);
			if(n/i!=i)
				r.push_back(n/i);
		}
	}
	return r;
}

//GCD
ll gcd(ll a,ll b)
{
	if(b>a)
	{
		ll t=a;
		a=b;
		b=t;
	}
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}

void print(pair<ll,ll>a)
{
	cout<<a.first<<" "<<a.second;
}
void print(vector<ll>a)
{
	for(auto x:a)
		cout<<x<<" ";
}
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
	return a.second<b.second;
}
//Main Solution

void solve()
{
	vector<ll>a;
	ll n=0,i,j,k,l;
	ll s=0;
	while(cin>>k)
	{
		a.push_back(k);
		s+=k;
		n++;
	}
	bool dp[a.size()+1][s+1];
	for(i=0;i<=n;i++)
	    dp[i][0]=true;
	for(i=1;i<=s;i++)
	    dp[0][i]=false;
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=s;j++){
	        dp[i][j]=dp[i-1][j];
	        if(a[i-1]<=j)
	            dp[i][j]|=dp[i-1][j-a[i-1]];
	    }
	}
	ll dif=INT64_MAX;
	for(i=s/2;i>=0;i--)
	{
	    if(dp[n][i])
	    {
	        dif=s-2*i;
	        break;
	    }
	}
	k=(s-dif)/2;
	cout<<(k+dif);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
	//cin>>t;
    while(t--)
    {
        solve();
    }
}
