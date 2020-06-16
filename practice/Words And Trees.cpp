#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define M 1000000007

//Prime Numbers

vector<bool> prime(N + 1, true);
void sieve()
{
    ll i, j, k;
    prime[0] = prime[1] = false;
    for (i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (j = i * i; j <= N; j++)
            {
                prime[j] = false;
            }
        }
    }
}

//Exponentiation

ll power(ll a, ll b)
{
    ll r = 1;
    while (b)
    {
        if (b % 2 == 1)
            r = r * a;
        b /= 2;
        a *= a;
    }
    return r;
}
ll power(ll a, ll b, ll m)
{
    a = a % m;
    ll r = 1;
    while (b)
    {
        if (b % 2 == 1)
            r = (r * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return r;
}

//Prime Factors

vector<ll> factors(ll n)
{
    vector<ll> r;
    ll i, j;
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            r.push_back(i);
            if (n / i != i)
                r.push_back(n / i);
        }
    }
    return r;
}

//GCD
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        ll t = a;
        a = b;
        b = t;
    }
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
//Graphs
vector<bool> bvisited(N, false);
vector<ll> bfs(ll V, vector<vector<ll>> G, ll s)
{
    vector<ll> order;
    queue<ll> q;
    bvisited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        order.push_back(s);
        for (auto x : G[s])
        {
            if (!bvisited[x])
            {
                bvisited[x] = true;
                q.push(x);
            }
        }
    }
    return order;
}
vector<bool> dvisited(N, false);
vector<ll>G[N];
vector<char>ch(N);
vector<vector<ll>>ans(N);
vector<ll> dfs(ll s)
{
    vector<ll> order(26,0);
    dvisited[s]=true;
    for(auto x:G[s])
    {
        if(!dvisited[x])
        {
            vector<ll>u=dfs(x);
            for(ll i=0;i<26;i++)
                order[i]+=u[i];
        }
    }
    order[ch[s]-'a']++;
    return ans[s]=order;
}

//Main Solution

void solve()
{
    ll n,q,i,j,k,l;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>ch[i];
    for(i=1;i<n;i++)
    {
        cin>>j>>k;
        G[j].push_back(k);
        G[k].push_back(j);
    }
    dfs(1);
    string s;
    while(q--)
    {
        vector<ll>a(26,0);
        cin>>k>>s;
        for(i=0;i<s.size();i++)
            a[s[i]-'a']++;
        l=0;
        for(i=0;i<26;i++)
        {
            j=a[i]-ans[k][i];
            if(j<0)j=0;
            l+=j;
        }
        cout<<l<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, i;
    for (i = 1; i <= t; i++)
    {
        solve();
    }
}
