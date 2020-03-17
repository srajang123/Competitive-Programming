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
    string a,b;
    ll i,j,k,c=1;
    cin>>a;
    char s=a[0];
    for(i=1;i<a.size();i++)
    {
        if(a[i]==s)
        {
            c++;
        }
        else
        {
            b.push_back(s);
            b+=to_string(c);
            c=1;
            s=a[i];
        } 
    }
    b.push_back(s);
    b+=to_string(c);
    if(b.size()<a.size())
        cout<<"YES\n";
    else
    {
        cout<<"NO\n";
    }
    
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