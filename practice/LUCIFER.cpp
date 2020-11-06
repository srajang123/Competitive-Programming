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
//Graphs
vector<bool>bvisited(N,false);
vector<vector<ll>>G(N);
vector<ll> bfs(ll s)
{
	vector<ll>order;
	queue<ll>q;
	bvisited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		order.push_back(s);
		for(auto x:G[s])
		{
			if(!bvisited[x])
			{
				bvisited[x]=true;
				q.push(x);
			}
		}
	}
	return order;
}
vector<bool>dvisited(N,false);
vector<ll> dfs(ll s)
{
	vector<ll>order;
	stack<ll>q;
	q.push(s);
	while(!q.empty())
	{
		ll v=q.top();
		q.pop();
		if(!dvisited[v])
		{
			order.push_back(v);
			dvisited[v]=true;
		}
		for(ll i=0;i<G[v].size();i++)
		{
			if(!dvisited[G[v][i]])
			{
				q.push(G[v][i]);
			}
		}
	}
	return order;
}
//My Functions
 
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
vector<ll>an(N+1,-1);
void bfs(vector<ll>s,vector<ll>e,ll n)
{
    vector<ll>d(n,INT64_MAX);
    queue<ll>q;
    for(auto x:s)
    {
        d[x]=0;
        q.push(x);
    }
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        for(auto x:G[v])
        {
            if(d[x]==INT64_MAX)
            {
                d[x]=d[v]+1;
                q.push(x);
            }
        }
    }
    for(auto x:e)
    {
        if(d[x]!=INT64_MAX)
            an[x]=d[x];
    }
}
void getDigitArray(string s,vector<ll>&d1)
{
    ll i=s.size()-1;
    while(i>=0)
    {
        d1.push_back(s[i]-'0');
        i--;
    }
}
void sub(vector<ll>&a)
{
    ll i=0,n=a.size(),c=1;
    while(i<n && c>0)
    {
        if(a[i]>=c)
        {
            a[i]-=c;
            c=0;
            break;
        }
        else
        {
            a[i]=9;
        }
        i++;
    }
    while(a.size()>0 && a.back()==0)
        a.pop_back();
}
ll dp[20][180][180][2];
ll countLUCIFER(ll i,ll se,ll so,ll msk,vector<ll>&a)
{
    if(i<0)
    {
        if(se-so>0 && prime[se-so])return 1;
        return 0;
    }
    if(dp[i][se][so][msk]!=-1 && msk!=1)
        return dp[i][se][so][msk];
    ll ret=0;
    ll k=msk?a[i]:9;
    for(ll j=0;j<=k;j++)
    {
        ll nt=(a[i]==j)?msk:0;
        ll p,q;
        p=se;
        q=so;
        if(i%2==1)
            p+=j;
        else
            q+=j;
        ret+=countLUCIFER(i-1,p,q,nt,a);
    }
    if(!msk)
        dp[i][se][so][msk]=ret;
    return ret;
}
ll solve()
{
    ll i,j,k,l,m,n;
    string a,b;
    cin>>a>>b;
    vector<ll>d1,d2;
    getDigitArray(a,d1);
    if(a!="0")
        sub(d1);
    ll s1=countLUCIFER(d1.size()-1,0,0,1,d1);
    getDigitArray(b,d2);
    ll s2=countLUCIFER(d2.size()-1,0,0,1,d2);
    ll ans=(s2-s1);
    cout<<ans<<"\n";
    return 1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
	cin>>t;
	sieve();
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        solve();
    }
}
