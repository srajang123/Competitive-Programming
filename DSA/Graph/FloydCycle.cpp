#include<bits/stdc++.h>
using namespace std;

int succ(vector<vector<int>>&G,int x)
{
    return G[x][0];
}

int main()
{
    int n,i,j,k,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<int>>G(n+1);
    while(m--)
    {
        cin>>i>>j;
        G[i].push_back(j);
    }
    k=1;
    i=succ(G,k);
    j=succ(G,succ(G,k));
    while(i!=j)
    {
        i=succ(G,i);
        j=succ(G,succ(G,j));
    }
    cout<<"Cycle begins at "<<i<<"\n";
    k=1;
    i=succ(G,i);
    while(i!=j)
    {
        i=succ(G,i);
        k++;
    }
    cout<<"Length of cycle is"<<k<<"\n";
}