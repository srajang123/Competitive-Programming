#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
#define ll long long
ll c=0;
map<pair<ll,ll>,ll>v;
ll pow(ll a,ll b)
{
    return a;
}
ll pow(ll a,ll b,ll m)
{
    return a;
}
void ktree(ll n,ll k,ll d,ll s,ll u)
{
    if(n<=0)
    {
        if(n==0)
        {
            if(u>0)
            {
                c++;
                v[{n,u}]=1;
            }
            else
            {
                v[{n,u}]=-1;
            }
        }
        return;
    }
    if(v[{n,u}]>0)
    {
        c++;
        return;
    }
    if(v[{n,u}]==-1)
        return;
    for(ll i=1;i<=k;i++)
    {
        ll j=u;
        if(i>=d)
            j++;
        ktree(n-i,k,d,s,j);
    }
}
void solve()
{
    ll n,k,d,i,j,l;
    cin>>n>>k>>d;
    ktree(n,k,d,0,0);
    cout<<c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}