#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
vector<ll>bit1(N),bit2(N);
ll n;
void update(vector<ll>&bit,ll i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=(i&-i);
    }
}
ll query(vector<ll>&bit,ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=(i&-i);
    }
    return s;
}
ll prefix_sum(ll i)
{
    return query(bit1,i)*i-query(bit2,i);
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll q,i,j,k,l;
        cin>>n>>q;
        for(i=0;i<N && i<n+100;i++)
            bit1[i]=bit2[i]=0;
        while(q--)
        {
            cin>>i>>j>>k;
            if(i==0)
            {
                cin>>l;
                update(bit1,j,l);
                update(bit1,k+1,-l);
                update(bit2,j,l*(j-1));
                update(bit2,k+1,-l*k);
            }
            else
            {
                l=prefix_sum(k)-prefix_sum(j-1);
                cout<<l<<"\n";
            }
        }
    }
} 
