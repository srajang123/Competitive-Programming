#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>tree;
void update(ll p,ll v,ll n)
{
    ll i;
    for(i=p;i<=n;i+=(i&-i))
        tree[i]+=v;
}
ll sum(ll p)
{
    ll a=0,i;
    for(i=p;i>0;i-=(i&-i))
        a+=tree[i];
    return a;
}
int main()
{
    ll i,j,k,l,n,q;
    cin>>n>>q;
    tree.assign(n+1,0);
    vector<ll>a(n),b(n,0);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            string s=to_string(a[i]);
            if(s[0]==s[s.size()-1])
                b[i]++;
        }
    }
    for(i=1;i<=n;i++)
    {
        update(i,b[i-1],n);
    }
    while(q--)
    {
        cin>>i>>j>>k;
        if(i==1)
        {
            cout<<sum(k)-sum(j-1)<<"\n";
        }
        else
        {
            a[j-1]=k;
            l=b[j-1];
            b[j-1]=0;
            i=j-1;
            if(a[i]>=0)
            {
                string s=to_string(a[i]);
                if(s[0]==s[s.size()-1])
                    {
                        b[j-1]++;
                    }
            }
            l=b[j-1]-l;
            update(j,l,n);
        }
    }
}