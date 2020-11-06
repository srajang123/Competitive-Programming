#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll dp[105][105][105];
 
ll ans(vector<ll>&a,ll n,ll i,ll k,ll c=0)
{
    if(i<0||n<0||k<0)return -1;
    if(k==0)return c;
    if(dp[n][i][k]!=-1 && dp[n][i][k]<c)return dp[n][i][k];
    ll p=-1,q=-1;
    if(a[i]!=-1)
        p=ans(a,n-1,i,k-i-1,c+a[i]);
    q=ans(a,n,i-1,k,c);
    if(p==-1)p=INT64_MAX;
    if(q==-1)q=INT64_MAX;
    p=min(p,q);
    p=(p==INT64_MAX?-1:p);
    //cout<<i<<":"<<k<<":"<<p<<"\n";
    return dp[n][i][k]=p;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        ll n,k,i,j,l;
        cin>>n>>k;
        vector<ll>a(k);
        for(i=0;i<k;i++)
            cin>>a[i];
        cout<<ans(a,n,k-1,k)<<'\n';
        //cout<<INT64_MAX;
    }
} 
