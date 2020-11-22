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
ll lis(vector<ll>a)
{
    ll n,i,j,k,l;
    n=a.size();
    vector<ll>b(n+1,INT64_MAX);
    b[0]=INT64_MIN;
    l=0;
    for(auto x:a)
    {
        j=upper_bound(b.begin(),b.end(),x)-b.begin()-1;
        l=max(l,j+1);
        b[j+1]=min(b[j+1],x);
    }
    return n-l;
}
void solve()
{
    ll n,m,r,c,i,j,k,l=0,x,y;
    cin>>n>>m>>r>>c>>x>>y;
    vector<string>a(n);
    vector<vector<ll>>le(n,vector<ll>(m,0)),ri(n,vector<ll>(m,0));
    for(i=0;i<n;i++)
        cin>>a[i];
    ll rx=r,cx=c;
deque<pair<ll,ll>>q;
    q.push_back({r-1,c-1});
    while(!q.empty())
    {
        pair<ll,ll>p=q.front();
        q.pop_front();
        r=p.first;
        c=p.second;
        if(r<0||r>=n||c<0||c>=m||a[r][c]=='*'||a[r][c]=='+')continue;
        if(le[r][c]<=x && ri[r][c]<=y)l++;
        a[r][c]='+';
        if(c-1>=0)
        {
            q.push_back({r,c-1});
            le[r][c-1]=le[r][c]+1;
            ri[r][c-1]=ri[r][c];
        }
        if(c+1<m)
        {
            q.push_back({r,c+1});
            ri[r][c+1]=ri[r][c]+1;
            le[r][c+1]=le[r][c];
        }
        if(r+1<n)
        {
            q.push_front({r+1,c});
            ri[r+1][c]=ri[r][c];
            le[r+1][c]=le[r][c];
        }
        if(r-1>=0)
        {
            q.push_front({r-1,c});
            ri[r-1][c]=ri[r][c];
            le[r-1][c]=le[r][c];
        }
    }
    cout<<l;
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
        cout<<'\n';
    }
}


