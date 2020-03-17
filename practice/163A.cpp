#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
#define ll long long
#define N 1000000007
ll pow(ll a,ll b)
{
    return a;
}
ll pow(ll a,ll b,ll m)
{
    return a;
}

void solve()
{
    string s,t;
    ll i,j,k=0;
    cin>>s>>t;
    ll n=s.size(),m=t.size();
    vector<vector<ll>>a(n+1,vector<ll>(m+1,0));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                a[i][j]=(a[i-1][j-1]+1)%N;
            }
            else
            {
                //a[i][j]=a[i][j-1];
            }
            
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            k+=a[i][j];
    }
    cout<<k;
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