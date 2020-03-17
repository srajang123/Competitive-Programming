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
    ll i,j,k,n,m,a;
    cin>>a>>m;
    set<ll>p,q;
    for(i=1;i*i<=m;i++)
    {
        if(m%i==0)
        {
            if((i-1)%a==0)
            {
                if((i-1)/a)
                    p.insert((i-1)/a);
            }
            if(m/i!=i)
            {
                if((m/i-1)%a==0)
                {
                    if((m/i-1)/a)
                        p.insert((m/i-1)/a);
                }
            }
        }
    }
    for(auto x:p)
    {
        i=a*x+1;
        if(m%i==0){
            j=m/i;
            k=j*x;
            q.insert(k);
        }
    }
    cout<<q.size()<<"\n";
    for(auto x:q)
        cout<<x<<" ";
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