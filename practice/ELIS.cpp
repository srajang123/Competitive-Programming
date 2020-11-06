#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lis(vector<ll>&a,ll n)
{
    ll i,j,k;
    vector<ll>lis(n,1);
    for(i=1;i<n;i++)
    {
        lis[i]=1;
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    return *max_element(lis.begin(),lis.end());
}
int main()
{
    ll i,j,k,l,n;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<lis(a,n);
} 
