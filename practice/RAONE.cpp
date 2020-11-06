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
ll dp[20][180][180][2];
ll getSum(ll i,ll se,ll so,ll msk,vector<ll>&a)
{
    if(i<0)
    {
        if(se-so==1)return 1;
        return 0;
    }
    if(dp[i][se][so][msk]!=-1 && msk!=1)
        return dp[i][se][so][msk];
    ll ret=0;
    ll k=msk?a[i]:9;
    for(ll j=0;j<=k;j++)
    {
        ll nt=(a[i]==j)?msk:0;
        ll p,q;
        p=se;
        q=so;
        if(i%2==1)
            p+=j;
        else
            q+=j;
        ret+=getSum(i-1,p,q,nt,a);
    }
    //cout<<i<<":"<<so<<","<<se<<"\n";
    //if(se-so==1)ret++;
    if(!msk)
        dp[i][se][so][msk]=ret;
    return ret;
}
ll code()
{
    ll a,b,i,j,k,l,m,n;
    cin>>a>>b;
    ll N=100000;
    memset(dp,-1,sizeof(dp));
    vector<ll>d1,d2;
    getDigitArray(a-1,d1);
    ll s1=getSum(d1.size()-1,0,0,1,d1);
    getDigitArray(b,d2);
    memset(dp,-1,sizeof(dp));
    ll s2=getSum(d2.size()-1,0,0,1,d2);
    cout<<s2-s1<<"\n";
    return 1;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
        code();
}  
