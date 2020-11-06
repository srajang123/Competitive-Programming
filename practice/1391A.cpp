#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,n;
        cin>>n;
        i=1;
        j=n;
        k=0;
        while(k++<n)
        {
            cout<<i<<" ";
            if(k++<n)
                cout<<j<<" ";
            i++;j--;
        }
        cout<<"\n";
    }
}
