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
    ll i,j=0,k=0,n;
    string s;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='L')
            j--;
        else
        {
            k++;
        }
    }
    cout<<(k-j+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}