#include<bits/stdc++.h>
using namespace std;
/*
    Complexity: O(V.E)
*/
int main()
{
    int n,i,j,k,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>G(n+1);
    vector<pair<pair<int,int>,int>>e;
    vector<int>d(n+1,INT_MAX),vis(n+1,0);
    while(m--)
    {
        cin>>i>>j>>k;
        G[i].push_back({j,k});
        G[j].push_back({i,k});
        e.push_back({{i,j},k});
    }
    d[1]=0;
    for(i=1;i<n;i++)
    {
        for(auto x:e)
        {
            if(d[x.first.first]+x.second<d[x.first.second])
                d[x.first.second]=d[x.first.first]+x.second;
        }
    }
    for(auto x:d)
        cout<<x<<" ";
}