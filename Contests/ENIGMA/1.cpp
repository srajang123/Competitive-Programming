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
    ll n,i,j,k,l,q,r;
    cin>>n;
    vector<ll>a(n+1,0);
    for(i=1;i<n+1;i++)
    {
        cin>>j;
        if(j%2==1)
            a[i]=1;
    }
    for(i=1;i<=n;i++)
        a[i]+=a[i-1];
    for(i=0;i<=n;i++)
        cout<<a[i]<<",";
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        if(r-l+1!=a[r]-a[l-1])
            cout<<"EVEN";
        else
        {
                cout<<"ODD";
        }
        cout<<"\n";
    }
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