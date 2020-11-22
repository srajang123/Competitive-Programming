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
bool primec(ll n)
{
    if(n<N)
        return prime[n];
    ll i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
bool isSub(string a,string b,ll n,ll m,ll c=0,ll bb=0)
{
    if(m==0)
    {
        if(bb==1)
            return true;
        return false;
    }
    if(n==0)return false;
    bool k=true;
    if(a[n-1]==b[m-1])
    {
        k=isSub(a,b,n-1,m-1,c+1,bb);
        if(bb==0)
            k|=isSub(a,b,n-1,m,c+1,1);
        return k;
    }
    if(c>0)
        bb=1;
    return isSub(a,b,n-1,m,c,bb);
}
void solve()
{
    ll i,j,k,n,m,l;
    string s,t;
    cin>>n>>m>>s>>t;
    /*vector<vector<ll>>a(n,vector<ll>(26,0));
    for(i=0;i<n;i++)
        a[i][s[i]-'a']++;
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<26;j++)
        {
            a[i][j]+=a[i+1][j];
        }
    }*/
    vector<ll>a(26,0),b(26,0);
    bool f=true;
    /*for(i=0;i<n;i++)
    {
        if(s[i]==t[i])continue;
        if(a[i][t[i]-'a']+b[t[i]-'a']>0)
        {
            b[t[i]-'a']--;
            b[s[i]-'a']++;
            continue;
        }
        if(s[i]!='z')
            {
            ll kk=1;
            for(j=i+1;j<n && j<=i+m-1;j++)
            {
                if(s[j]==s[j-1])
                    kk++;
                else
                {
                    if(a[i][s[j-1]-'a']+b[s[j-1]-'a']>0)
                    {
                        b
                    }
                }
            }
            cout<<i<<":"<<kk<<"+"<<m<<"\n";
            if(kk==m)
            {
                i=i+m-1;
                continue;
            }
        }
        f=false;
    }*/
    for(i=0;i<n;i++)
    {
        a[s[i]-'a']++;
        b[t[i]-'a']++;
    }
    while(true)
    {
        l=0;
        for(i=0;i<26;i++)
        {
            if(a[i]>0 && b[i]>0)
            {
                ll u=min(a[i],b[i]);
                a[i]-=u;
                b[i]-=u;
                l++;
            }
        }
        for(i=0;i<25;i++)
        {
            if(a[i]>0 && a[i]/m>0)
            {
                //cout<<i<<":"<<a[i]<<"\n";
                l++;
                ll u=(a[i]/m);
                u*=m;
                a[i]-=u;
                a[i+1]+=u;
                break;
            }
        }
        //cout<<l<<"\n";
        if(l==0)break;
    }
    for(i=0;i<26;i++)
        if(a[i]>0)f=false;
    if(f)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
	cin>>t;
	sieve();
    while(t--)
    {
        solve();
    }
}

