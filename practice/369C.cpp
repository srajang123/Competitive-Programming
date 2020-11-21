#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>>G(100005);
map<pair<ll,ll>,ll>a;
vector<ll>b(100005,0),c(100005,0);
ll dfs1(ll s,ll p=-1)
{
    ll c=0;
    for(auto x:G[s])
    {
        if(x!=p)
            c+=dfs1(x,s);
    }
    if(a[{s,p}])c++;
    return b[s]=c;
}
ll dfs2(ll s,ll p=-1,ll v=0)
{
    if(v==0 && s!=1)return 0;
    //cout<<s<<':'<<v<<"\n";
    ll f=0;
    if(b[s]>0)v=1;
    for(auto x:G[s])
    {
        if(x!=p && b[x]>0)
        {
            dfs2(x,s,v);
            f++;
        }
    }
    if(f==0 && v>0)
    {
        for(auto x:G[s])
        {
            if(x!=p && f==0)
            {
                dfs2(x,s,v);
                f++;
            }
        }
    }
    if(G[s].size()==1)
        c[s]=1;
    return 0;
}
int main()
{
    ll n,i,j,k,l;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>j>>k>>l;
        G[j].push_back(k);
        G[k].push_back(j);
        if(l==2)
        {
            a[{j,k}]++;
            a[{k,j}]++;
        }
    }
    dfs1(1);
    dfs2(1);
    vector<ll>ans;
    for(i=1;i<=n;i++)   
    {
        if(c[i] && i!=1)
            ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)
        cout<<x<<" ";
}
