#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5001][5001][2];
ll recur(vector<ll>&a,ll i,ll f,ll el=-1)
{
    if(i<0)return 0;
    ll si=(f==-1?0:1);
    if(el!=-1 && dp[i][el][si]!=-1)return dp[i][el][si];
    ll c=0;
    if(f*a[i]>0 && (el==-1||abs(a[i])<abs(a[el])))
    {
        c+=1+recur(a,i-1,f*-1,i);
    }
    c=max(c,recur(a,i-1,f,el));
    return dp[i][el][si]=c;
}
int main()
{
    ll i,j,k,n;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    k=recur(a,n-1,1);
    //memset(dp,-1,sizeof(dp));
    j=recur(a,n-1,-1);
    cout<<max(j,k);
} 
