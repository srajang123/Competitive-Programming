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
		ll i,j,k,n,m;
		cin>>n>>k;
		vector<ll>a(n),b(n,0),c(n),d(n);
		vector<pair<ll,ll>>p,q;
		for(i=0;i<n;i++)
		{
			cin>>a[i]>>c[i]>>d[i];
			if(c[i])
				b[i]++;
			if(d[i])
				b[i]++;
			if(c[i] && b[i]!=2)
			{
				p.push_back({a[i],i});
			}
			if(d[i] && b[i]!=2)
			{
				q.push_back({a[i],i});
			}
		}
		sort(p.begin(),p.end());
		sort(q.begin(),q.end());
		vector<ll>cc(1,0),dd(1,0),ee(1,0);
		for(i=0;i<n;i++)
		{
			if(b[i]==2)
				ee.push_back(a[i]);
		}
		for(auto x:p)
			cc.push_back(x.first);
		for(auto x:q)
			dd.push_back(x.first);
		for(i=1;i<cc.size();i++)
			cc[i]+=cc[i-1];
		for(i=1;i<dd.size();i++)
			dd[i]+=dd[i-1];
		sort(ee.begin(),ee.end());
		for(i=1;i<ee.size();i++)
			ee[i]+=ee[i-1];
		ll t=INT64_MAX,u=k-(ll)ee.size();
		for(i=1;i<=min(k,(ll)ee.size()-1);i++)
		{
			if(cc.size()>k-i && dd.size()>k-i)
				t=min(t,ee[i]+dd[k-i]+cc[k-i]);
		}
		if(t==INT64_MAX)
			t=-1;
		cout<<t;
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
