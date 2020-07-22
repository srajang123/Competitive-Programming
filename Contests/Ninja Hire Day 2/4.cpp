#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll count(string a,string b)
{
    ll m=a.size();
    ll n=b.size();
    ll look[m+1][n+1]={{0}},i,j;
    for(i=0;i<=n;i++)
        look[0][i]=0;
    for(i=0;i<=m;i++)
        look[i][0]=1;
	for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
                look[i][j]=look[i-1][j-1]+look[i-1][j];
        	else
                look[i][j]=look[i-1][j];
        }
    }
    return look[m][n];
}
int main(){
    // write your code
    string s,t;
    cin>>s;
    ll q,i,j,k,n;
    char x;
    cin>>q;
    while(q--)
    {
        cin>>x>>n;
        if(x=='p')
        {
            t=s.substr(0,n);
        }
        else
        {
            t=s.substr((ll)s.size()-n,n);
        }
        cout<<count(t,"ninjas")<<"\n";
    }
    return 0;
}
//
