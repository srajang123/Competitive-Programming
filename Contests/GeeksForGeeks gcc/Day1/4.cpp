#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000001
vector<bool>prime(N,true);
void seive()
{
    ll i,j,k;
    for(i=0;i<2;i++)
        prime[i]=false;
    for(i=2;i*i<=N;i++)
    {
        if(prime[i])
        {
            for(j=i*i;j<N;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}
int main()
{
    seive();
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,n;
        cin>>n;
        vector<ll>a(n),b(n,0),c;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(prime[a[i]] && prime[a[i]-2])
            {
                b[i]=1;
                c.push_back(a[i]);
            }
        }
        sort(c.begin(),c.end());
        j=0;
        for(i=0;i<n;i++)
        {
            if(b[i]==1)
            {
                a[i]=c[j++];
            }
        }
        for(auto x:a)
            cout<<x<<" ";
        cout<<"\n";
    }
}