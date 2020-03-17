#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll phi(ll n)
{
    ll r=n,i,j;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
        while(n%i==0)
            n/=i;
            r-=r/i;
        }
    }
    if(n>1)
        r-=r/n;
    return r;
}
int main()
{
    ll n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"The value of phi("<<n<<") is: "<<phi(n);
}