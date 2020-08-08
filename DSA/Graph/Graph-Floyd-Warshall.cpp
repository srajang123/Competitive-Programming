#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
/*
    Complexity: O(V*V*V)=O(V^3)
*/
int main()
{
    int n,i,j,k,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>G(n+1);
    vector<vector<int>>d(n+1,vector<int>(n+1,MAX));
    while(m--)
    {
        cin>>i>>j>>k;
        G[i].push_back({j,k});
        G[j].push_back({i,k});
        d[i][j]=k;
        d[j][i]=k;
    }
    for(i=1;i<=n;i++)
        d[i][i]=0;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++)   
    {
        cout<<i<<":"<<" ";
        for(j=1;j<=n;j++)
            cout<<d[i][j]<<" ";
        cout<<"\n";
    }
}