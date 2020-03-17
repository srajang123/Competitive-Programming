#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k=0,n,c=0;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1]+1)
                c++;
            else
            {
                k+=c>0?1:0;
                c=0;
            }
        }
        k+=c>0?1:0;
        cout<<k<<"\n";
    }
}