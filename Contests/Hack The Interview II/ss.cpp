#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,j,k,s=0;
        cin>>n;
        vector<ll>a;//used just for showing you the use of vector
        //No need to use it here
        for(i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                a.push_back(i);
                if(i!=n/i)
                    a.push_back(n/i);
            }
        }
        for(i=0;i<a.size();i++)
        {
            if(a[i]!=n)
                s+=a[i];
        }
        if(s==n)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
}