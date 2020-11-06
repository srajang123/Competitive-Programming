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
bool f;
void dfs(vector<string>&a,ll i,ll j,char x,vector<vector<ll>>&v)
{
    if(i<0||j<0||i>=a.size()||j>=a.size())return;
    if(v[i][j]==1)return;
    v[i][j]=1;
    if(a[i][j]=='F')
    {
        f=true;
        return;
    }
    if(i+1<a.size() &&(a[i+1][j]==x||a[i+1][j]=='F'))
        dfs(a,i+1,j,x,v);
    if(j+1<a.size() &&(a[i][j+1]==x||a[i][j+1]=='F'))
        dfs(a,i,j+1,x,v);
    if(i-1>=0 &&(a[i-1][j]==x||a[i-1][j]=='F'))
        dfs(a,i-1,j,x,v);
    if(j-1>=0 &&(a[i][j-1]==x||a[i][j-1]=='F'))
        dfs(a,i,j-1,x,v);
        
    if(i+1<a.size() && j+1<a.size() &&(a[i+1][j+1]==x||a[i+1][j+1]=='F'))
        dfs(a,i+1,j+1,x,v);
    if(i+1<a.size() && j-1>=0 &&(a[i+1][j-1]==x||a[i+1][j-1]=='F'))
        dfs(a,i+1,j-1,x,v);
    if(i-1>=0 && j+1<a.size() &&(a[i-1][j+1]==x||a[i-1][j+1]=='F'))
        dfs(a,i-1,j+1,x,v);
    if(i-1>=0 && j-1>=0 &&(a[i-1][j-1]==x||a[i-1][j-1]=='F'))
        dfs(a,i-1,j-1,x,v);
    v[i][j]=0;
}
void solve()
{
    ll i,j,k,n,m;
    cin>>n;
    vector<string>a(n),aa(n);
     vector<string>v(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    f=false;
    for(i=0;i<n;i++)
    {
        v[i]=a[i];
        aa[i]=a[i];
    }
    aa[0][0]=v[0][0]='s';
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(v[i][j]=='F'||v[i][j]=='2')
            {
                if(i-1>=0 && (v[i-1][j]=='2'||v[i-1][j]=='s'||v[i-1][j]=='1'))
                    v[i-1][j]='2';
                if(j-1>=0 && (v[i][j-1]=='2'||v[i][j-1]=='s'||v[i][j-1]=='1'))
                    v[i][j-1]='2';
                if(i-1>=0 && j-1>=0 && (v[i-1][j-1]=='2'||v[i-1][j-1]=='s'||v[i-1][j-1]=='1'))
                    v[i-1][j-1]='2';
            }
        }
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(aa[i][j]=='F'||aa[i][j]=='2')
            {
                if(i-1>=0 && (aa[i-1][j]=='2'||aa[i-1][j]=='s'||aa[i-1][j]=='0'))
                   aa[i-1][j]='2';
                if(j-1>=0 && (aa[i][j-1]=='2'||aa[i][j-1]=='s'||aa[i][j-1]=='0'))
                    aa[i][j-1]='2';
                if(i-1>=0 && j-1>=0 && (aa[i-1][j-1]=='2'||aa[i-1][j-1]=='s'||aa[i-1][j-1]=='0'))
                    aa[i-1][j-1]='2';
            }
        }
    }/*
    for(i=0;i<n;i++)
    {
        cout<<aa[i]<<" "<<v[i]<<"\n";
    }*//*
    if(aa[0][0]=='2'||v[0][0]=='2')f=true;
    if(!f)
    {
        cout<<0<<"\n";
        return;
    }*/
    ll c=0;
    vector<pair<ll,ll>>ans;/*
    if(aa[0][0]=='2')
    {
        if(aa[0][1]=='2' && aa[1][0]=='2')
        {
            if(aa[n-1][n-2]=='2' && aa[n-2][n-1]=='2')
            {
                ans.insert({1,2});
                ans.insert({2,1});
            }
            else if(aa[n-1][n-2]=='2')
                ans.insert({n,n-1});
            else
                ans.insert({n-1,n});
        }
        else if(aa[0][1]=='2')
            ans.insert({1,2});
        else
            ans.insert({2,1});
    }
    if(v[0][0]=='2')
    {
        if(v[0][1]=='2' && v[1][0]=='2')
        {
            if(v[n-1][n-2]=='2' && v[n-2][n-1]=='2')
            {
                ans.insert({1,2});
                ans.insert({2,1});
            }
            else if(v[n-1][n-2]=='2')
                ans.insert({n,n-1});
            else
                ans.insert({n-1,n});
        }
        else if(v[0][1]=='2')
            ans.insert({1,2});
        else
            ans.insert({2,1});
    }
    */
    if(a[0][1]=='0' && a[1][0]=='0')
    {
        if(a[n-1][n-2]==a[n-2][n-1])
        {
            if(a[n-1][n-2]=='0')
            {
                ans.push_back({1,2});
                ans.push_back({2,1});
            }
        }
        else
        {
            if(a[n-1][n-2]=='1')
                ans.push_back({n-1,n});
            else
                ans.push_back({n,n-1});
        }
    }
    else if(a[0][1]=='1' && a[1][0]=='1')
    {
        if(a[n-1][n-2]==a[n-2][n-1])
        {
            if(a[n-1][n-2]=='1')
            {
                ans.push_back({1,2});
                ans.push_back({2,1});
            }
        }
        else
        {
            if(a[n-1][n-2]=='0')
                ans.push_back({n-1,n});
            else
                ans.push_back({n,n-1});
        }
    }
    else
    {
        if(a[0][1]=='0')
        {
            if(a[n-1][n-2]==a[n-2][n-1] && a[n-1][n-2]=='0')
                ans.push_back({1,2});
            else if(a[n-1][n-2]==a[n-2][n-1] && a[n-1][n-2]=='1')
                ans.push_back({2,1});
            else if(a[n-1][n-2]=='0')
            {
                ans.push_back({1,2});
                ans.push_back({n-1,n});
            }
            else
            {
                ans.push_back({1,2});
                ans.push_back({n,n-1});
            }
        }
        else
        {
            if(a[n-1][n-2]==a[n-2][n-1] && a[n-1][n-2]=='0')
                ans.push_back({2,1});
            else if(a[n-1][n-2]==a[n-2][n-1] && a[n-1][n-2]=='1')
                ans.push_back({1,2});
            else if(a[n-1][n-2]=='0')
            {
                ans.push_back({2,1});
                ans.push_back({n-1,n});
            }
            else
            {
                ans.push_back({2,1});
                ans.push_back({n,n-1});
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)
    {
        print(x);
        cout<<"\n";
    }
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
