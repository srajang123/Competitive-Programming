#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,ll> fib(ll n)
{
    if(n==0)return {0,1};
    auto p=fib(n>>1);
    ll c=p.first*(2*p.second-p.first);
    ll d=p.second*p.second+p.first*p.first;
    if(n%2==0)
        return {c,d};
    else
    {
            return {d,c+d};
    }
    
}
int main()
{
    ll n,i;
    cout<<"Enter n:";
    cin>>n;
    cout<<"The fibonacci numbers are:\n";
    for(i=0;i<=n;i++)
    {
        cout<<fib(i).first<<", ";
    }
}