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
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
void solve()
{
    ll i,j,k,n,x;
    ll a=INT64_MAX,b=INT64_MAX;
    cin>>x;
    for(i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            if(lcm(i,x/i)==x)
            {
                if(max(a,b)>max(i,x/i))
                {
                    a=i;
                    b=x/i;
                }
            }
        }
    }
    cout<<a<<" "<<b; 
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