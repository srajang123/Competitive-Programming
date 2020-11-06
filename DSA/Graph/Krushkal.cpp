#include<bits/stdc++.h>
using namespace std;

/*
    Complexity: O((E+V)logV)
*/
vector<int>id(100005,-1);
int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(int x,int y)
{
    int p,q;
    p=root(x);
    q=root(y);
    id[p]=id[q];
}
int main()
{
    int n,i,j,k,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>e;
    vector<bool>vis(n+1,false);
    while(m--)
    {
        cin>>i>>j>>k;
        e.push_back({k,{i,j}});
    }
    sort(e.begin(),e.end());
    m=e.size();
    int mn=0;
    for(i=0;i<=n;i++)
        id[i]=i;
    for(i=0;i<m;i++)
    {
        int x,y,c;
        x=e[i].second.first;
        y=e[i].second.second;
        c=e[i].first;
        if(root(x)!=root(y))
        {
            mn+=c;
            union1(x,y);
        }
    }
    cout<<mn;
}