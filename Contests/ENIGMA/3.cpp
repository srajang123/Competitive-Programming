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
    ll n,k,i,j,l;
    cin>>n>>k;
    l=(k*(k+1))/2;
    j=n/l;
    if(j>0)
    {
        ll u=n-l*j;
        if(u==0||(u%j==0))
            cout<<j;
        else
        {
            u%=j;
            if(__gcd(j,u)!=1)
                cout<<__gcd(j,u);
            else
            {
                cout<<1;
            }
            
        }
        
    }
    else
    {
        cout<<"-1";
    }
    
    cout<<"\n";
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