#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,n,mx=0;
        cin>>n;
        vector<ll>a(n),b;
        b.clear();
        for(i=0;i<n;i++)
            cin>>a[i];
        k=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                k++;
            }
            else
            {
                b.push_back(k);
                if(k!=0)b.push_back(0);
                k=0;
            }
        }
        if(k!=0)b.push_back(k);
        for(i=0;i<b.size();i++)
            mx=mx>b[i]?mx:b[i];
        for(i=0;i<b.size();i++)
        {
            if(i+3<b.size())
            {
                if(b[i+1]==b[i+2] && b[i+1]==0)
                    mx=mx>b[i]+b[i+3]?mx:b[i]+b[i+3];
            }
            if(i+2<b.size())
            {
                if(b[i+1]==0)
                {
                    j=b[i]+b[i+2]-1;
                    mx=mx>j?mx:j;
                }
            }
        }
        cout<<mx<<"\n";
    }
	// Write your code here
}

