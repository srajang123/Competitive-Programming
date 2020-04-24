#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k;
    cin>>n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<(n/i);
            break;
        }
    }
}

