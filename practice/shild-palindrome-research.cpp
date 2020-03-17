#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>tree;
void update(ll p,vector<ll>v,ll n)
{
    ll i,j;
    for(i=p;i<=n;i+=(i&-i))
    {
        for(j=0;j<26;j++)
            tree[i][j]+=v[j];
    }
}
vector<ll> sum(ll p)
{
    ll a=0,i;
    vector<ll>b(26,0);
    for(i=p;i>0;i-=(i&-i))
    {
        for(ll j=0;j<tree[i].size();j++)
            b[j]+=tree[i][j];
    }
    return b;
}
int main()
{
    ll i,j,k,l,n,q;
    string s;
    cin>>n>>q>>s;
    char x;
    tree.assign(n+1,vector<ll>(26,0));
    for(i=1;i<=n;i++)
    {
        vector<ll>ss(26,0);
        ss[s[i]-97]++;
        update(i,ss,n);
    }
    while (q--)
    {
        cin>>i;
        if(i==1)
        {
            cin>>j>>x;
            vector<ll>a=sum(j),c;
            vector<ll>b=sum(j-1),d;
            for(i=0;i<26;i++)
                {
                    cout<<a[i]<<","<<b[i]<<"\n";
                    a[i]-=b[i];
                    cout<<a[i]<<","<<b[i]<<"\n";
                    if(a[i]==1)
                        cout<<"=>"<<i<<"<=";
                }
                cout<<"||"<<s[j-1];
            a[s[j-1]-97]--;
            s[j-1]=x;
            a[s[j-1]-97]++;
            update(j,a,n);
        }
        else
        {
    for(i=0;i<=n;i++)
    {
        for(j=0;j<26;j++)
            cout<<tree[i][j]<<":";
        cout<<"\n";
    }
            cin>>j>>k;
            cout<<s<<"\n";
            vector<ll>a,b;
            a=sum(k);
            b=sum(j-1);
            j=0;
            for(i=0;i<26;i++)
            {
                a[i]-=b[i];
                cout<<a[i]<<",";
                if(a[i]%2==1)
                    j++;
            }
            if(j<=1)
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
    }
    
}