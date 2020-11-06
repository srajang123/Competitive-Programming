#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
void getDigitArray(string s,vector<ll>&d1)
{
    ll i=s.size()-1;
    while(i>=0)
    {
        d1.push_back(s[i]-'0');
        i--;
    }
}
void sub(vector<ll>&a)
{
    ll i=0,n=a.size(),c=1;
    while(i<n && c>0)
    {
        if(a[i]>=c)
        {
            a[i]-=c;
            c=0;
            break;
        }
        else
        {
            a[i]=9;
        }
        i++;
    }
    while(a.size()>0 && a.back()==0)
        a.pop_back();
}
ll dp[51][51][51][51][2];
ll get369(ll i,ll c9,ll c6,ll c3,ll msk,vector<ll>&a)
{
    if(i<0)
    {
        if(c9==c6 && c6==c3 && c3>0)return 1;
        return 0;
    }
    if(i<2)
    {
        if(c9==0&&c3==0&&c6==0)return 0;
    }
    if(dp[i][c9][c6][c3][msk]!=-1 && msk!=1)
        return dp[i][c9][c6][c3][msk];
    ll ret=0;
    ll k=msk?a[i]:9;
    for(ll j=0;j<=k;j++)
    {
        ll nt=(a[i]==j)?msk:0;
        ll p,q,r;
        p=c9;
        q=c6;
        r=c3;
        if(j==9)p++;
        if(j==6)q++;
        if(j==3)r++;
        ret=(ret+get369(i-1,p,q,r,nt,a))%M;
    }
    if(!msk)
        dp[i][c9][c6][c3][msk]=ret;
    return ret;
}
ll code()
{
    ll i,j,k,l,m,n;
    string a,b;
    cin>>a>>b;
    ll N=100000;
    vector<ll>d1,d2;
    getDigitArray(a,d1);
    if(a!="0")
        sub(d1);
    ll s1=get369(d1.size()-1,0,0,0,1,d1);
    getDigitArray(b,d2);
    ll s2=get369(d2.size()-1,0,0,0,1,d2);
    ll ans=(s2-s1)%M;
    ans=(ans+M)%M;
    cout<<ans<<"\n";
    return 1;
}
int main()
{
    ll t;
    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--)
        code();
}  
