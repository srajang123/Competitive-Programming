#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll a,ll b)
{
    return a^b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k=0,n;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                ll p=f(a[i],a[j]);
                k=k>p?k:p;
            }
        }
        cout<<k<<"\n";
    }
}