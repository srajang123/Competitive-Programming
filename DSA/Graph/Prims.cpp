#include<bits/stdc++.h>
using namespace std;

/*
    Complexity: O(V*V*V)=O(V^3)
*/
int main()
{
    int n,i,j,k,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>G(n+1);
    while(m--)
    {
        cin>>i>>j>>k;
        G[i].push_back({j,k});
        G[j].push_back({i,k});
    }
}