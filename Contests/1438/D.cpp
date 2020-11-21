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
void solve()
{
    ll n,i,j,k,m,l;
    cin>>n;
    vector<ll>a(n);
    unordered_map<ll,vector<ll>>b;
    l=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        l^=a[i];
        b[a[i]].push_back(i);
    }
    /*
    i=j=-1;
    for(auto x:b)
    {
        if(x.second.size()>1)
        {
            i=x.second[0];
            j=x.second[1];
            break;
        }
    }
    if(i==j && i==-1)
    {
        cout<<"NO\n";
        return;
    }*/
    vector<pair<ll,pair<ll,ll>>>ss;
    if(n%2)
        k=n-3;
    else
        k=n-4;
    for(i=0;i<=k;i+=2)
    {
        a[i]=a[i+1]=a[i+2]=a[i]^a[i+1]^a[i+2];
        ss.push_back({i,{i+1,i+2}});
    }
    for(i=k;i>1;i-=2)
    {
        a[i]=a[i-1]=a[i-2]=a[i]^a[i-1]^a[i-2];
        ss.push_back({i-2,{i-1,i}});
    }
    if(n%2==0 && l!=0)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    cout<<ss.size()<<'\n';
    for(auto x:ss)
    {
        cout<<x.first+1<<" "<<x.second.first+1<<" "<<x.second.second+1<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
}
