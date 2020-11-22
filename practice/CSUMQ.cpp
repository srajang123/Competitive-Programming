#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
vector<ll>t(4*N);
ll n;
void build(vector<ll>&a,ll v,ll tl,ll tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else
    {
        ll tm=(tl+tr)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
ll sum(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 0;
    else if(l==tl && r==tr)
        return t[v];
    ll tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}
int main()
{
    ll tr=1;
    while(tr--)
    {
        ll q,i,j,k,l;
        cin>>n;
        vector<ll>a(n+1);
        for(i=0;i<n;i++)
        {
            cin>>j;
            a[i]=j;
        }
        build(a,1,0,n-1);
        cin>>q;
        while(q--)
        {
            cin>>i>>j;
            {
                l=sum(1,1,n,i+1,j+1);//,sum(1,1,n,i,j);
                cout<<l<<"\n";
            }
        }
    }
} 
