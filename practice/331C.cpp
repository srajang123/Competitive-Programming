#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,k,l,c=0;
    cin>>n;
    while(n>0)
    {
        k=n;
        j=0;
        while(k>0)
        {
            j=max(j,k%10);
            k/=10;
        }
        n-=j;
        c++;
    }
    cout<<c;
}
