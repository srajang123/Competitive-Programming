#include<bits/stdc++.h>
using namespace std;
#define ll long long
void getDigitArray(ll n,vector<ll>&d1)
{
    while(n)
    {
        d1.push_back(n%10);
        n/=10;
    }
}
ll dp[65][180][2];
ll getSum(ll i,ll s,ll msk,vector<ll>&a)
{
    if(i<0)return s;
    if(dp[i][s][msk]!=-1 && msk!=1)
        return dp[i][s][msk];
    ll ret=0;
    ll k=msk?a[i]:9;
    for(ll j=0;j<=k;j++)
    {
        ll nt=(a[i]==j)?msk:0;
        ret+=getSum(i-1,s+j,nt,a);
    }
    if(!msk)
        dp[i][s][msk]=ret;
    return ret;
}
ll code()
{
    ll a,b,i,j,k,l,m,n;
    cin>>a>>b;
    if(a==b && a==-1)return -1;
    ll N=100000;
    memset(dp,-1,sizeof(dp));
    vector<ll>d1,d2;
    getDigitArray(a-1,d1);
    ll s1=getSum(d1.size()-1,0,1,d1);
    getDigitArray(b,d2);
    ll s2=getSum(d2.size()-1,0,1,d2);
    cout<<s2-s1<<"\n";
    return 1;
}
int main()
{
    while(code()!=-1);
} 
