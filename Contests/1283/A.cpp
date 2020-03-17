#include<bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(),a.end())
#define ll long long

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
    ll i,j,k,h,m;
    cin>>h>>m;
    h=h*60+m;
    k=24*60;
    k-=h;
    cout<<k<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}