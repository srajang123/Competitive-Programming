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
    ll n,i,j,k,l=0,r=0;
    cin>>n;
    ll m,c,x,y,p;
    cin>>m>>c;
    while(n--)
    {
        cin>>x>>y>>p;
        k=y-m*x-c;
        if(k>0)
            l+=p;
        else
        {
            r+=p;
        }
        
    }
    cout<<(l>r?l:r);
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