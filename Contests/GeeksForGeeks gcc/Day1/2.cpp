#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string a,b,c,d;
        cin>>a>>b;
        ll i,j,k;
        for(i=0;i<a.size();i++)
        {
            if(a[i]!='#')
            {
                c.push_back(a[i]);
            }
            else
            {
                if(c.back()=='Z')
                  c[c.size()-1]='A';
                else
                    c[c.size()-1]=c.back()+1;
            }
        }
        for(i=0;i<b.size();i++)
        {
            if(b[i]!='#')
            {
                d.push_back(b[i]);
            }
            else
            {
                if(d.back()=='Z')
                  d[d.size()-1]='A';
                else
                    d[d.size()-1]=d.back()+1;
            }
        }
        if(c==d)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}