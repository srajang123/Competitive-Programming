#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pow(ll a,ll b)
{
    return a;
}
ll pow(ll a,ll b,ll m)
{
    return a;
}
pair<ll,ll> maxSum(vector<ll>a,ll n)
{
    ll maxFar=INT_MIN,maxEnd=0,s=0,e=0,p=0,i;
    for(i=0;i<n;i++)
    {
        maxEnd+=a[i];
        if(maxFar<maxEnd)
        {
            maxFar=maxEnd;
            s=p;
            e=i;
        }
        if(maxEnd<=0)
        {
            maxEnd=0;
            p=i+1;
        }
    }

    return {maxFar,e-s+1};
}
void solve()
{
    ll i,j,k,n,p=0,mx=0,s=0;
    pair<ll,ll>b;
    bool x=true;
    cin>>n;
    vector<ll>a(n);
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        p+=a[i];
    }
    b=maxSum(a,n);
    //cout<<"*"<<b.first<<"=>"<<b.second;
    if(b.first<p||b.second==n)
        cout<<"YES";
    else
    {
        cout<<"NO";
    }
    cout<<"\n";
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