#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>tree;
void update(ll p,ll v,ll n)
{
    ll i;
    for(i=p;i<=n;i+=(i&-i))
        tree[i]+=v;
}
ll sum(ll p)
{
    ll a=0,i;
    for(i=p;i>0;i-=(i&-i))
        a+=tree[i];
    return a;
}
int main()
{
    ll i,j,k,n;
    cin>>n;
    tree.assign(n+1,0);
    vector<ll>a(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        update(i,a[i-1],n);
    }
    for(i=0;i<=n;i++)
    {
        cout<<"Sum till "<<i<<" element:"<<sum(i)<<"\n";
    }
}