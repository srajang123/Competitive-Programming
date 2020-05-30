#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define M 1000000007

//Prime Numbers

vector<bool>prime(N+1,true);
void sieve()
{
	int i,j,k;
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

int power(int a,int b)
{
	int r=1;
	while(b)	
	{
		if(b%2==1)
			r=r*a;
		b/=2;
		a*=a;		
	}
	return r;
}
int power(int a,int b,int m)
{
	a=a%m;
	int r=1;
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

vector<int> factors(int n)
{
	vector<int>r;
	int i,j;
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
int gcd(int a,int b)
{
	if(b>a)
	{
		int t=a;
		a=b;
		b=t;
	}
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}
//Graphs
vector<bool>bvisited(N,false);
vector<int> bfs(int V,vector<vector<int>>G,int s)
{
	vector<int>order;
	queue<int>q;
	bvisited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
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
}/*
void dfs(int zz,vector< vector<int> > &edge,int s,vector<bool>&visit)
{
	visit[s]=true;
	for(int i=0;i<edge[s].size();i++)
	{
		int d=edge[s][i];
		if(visit[d]==false)
			dfs(zz,edge,d,visit);
	}
}*/
void dfs(int V,vector<vector<int>>G,int s,vector<bool>&dvisited)
{
	dvisited[s]=true;
	for(int i=0;i<G[s].size();i++)
	{
		int x=G[s][i];
		if(dvisited[x]==false)
			dfs(V,G,x,dvisited);
	}
}
//Main Solution

void solve()
{
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	vector<vector<int>>G(n);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&j,&k);
		G[j].push_back(k);
		G[k].push_back(j);
	}
	k=0;
	vector<bool>dvisited(n,false);
	for(i=0;i<n;i++)
	{
		if(!dvisited[i])
		{
			k++;
			dfs(0,G,i,dvisited);
		}
	}
	printf("%d\n",k);
	/*G.clear();
	dvisited.clear();*/
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    int t=1;
	scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}
