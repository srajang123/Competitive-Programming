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
    ll n,i,j,k,c=0;
    cin>>n;
    vector<ll>a(n),b(n,0);
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        if(a[i]<a[b[i-1]])
            b[i]=i;
        else
        {
            b[i]=b[i-1];
        } 
    }
    i=n-1;
    k=0;
    while(i>=0)
    {
        j=i;
        i=b[i];
        c+=(j+1)*(a[b[i]]-k);
        //cout<<i<<","<<j<<":"<<b[i]<<"=>"<<a[b[i]]<<";"<<k<<"====>"<<c<<endl;
        k=a[b[i]];
        i--;
    }
    cout<<c<<"\n";
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