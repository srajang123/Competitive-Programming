#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    // write your code
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a<b)
        {
         	ll k=1,i;
            for(i=1;i<=a;i++)
            {
                k=(k*i)%b;
            }
            cout<<k<<"\n";
        }
        else
            cout<<0<<"\n";
    }
    return 0;
}
