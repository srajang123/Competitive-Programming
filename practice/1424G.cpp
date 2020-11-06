#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t=1;
    while(t--)
    {
        ll n,i,j=0,k=0,l;
        cin>>n;
        vector<pair<ll,ll>>a;
        for(i=0;i<n;i++)
        {
            cin>>j>>k;
            a.push_back({j,1});
            a.push_back({k,-1});
        }
        j=k=0;
        sort(a.begin(),a.end());
        for(i=0;i<a.size();i++)
        {
            j+=a[i].second;
            if(j>k)
            {
                k=j;
                l=a[i].first;
            }
        }
        cout<<l<<" "<<k;
    }
}
