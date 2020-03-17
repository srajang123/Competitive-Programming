/*
Rotate a given String in specified direction by specified magnitude.

After each rotation make a note of first character of the rotated String, After all rotation are performed the accumulated first character as noted previously will form another string, say FIRSTCHARSTRING.

Check If FIRSTCHARSTRING is an Anagram of any substring of the Original string.

If yes print "YES" otherwise "NO".
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s,t;
    ll i,j,k,n,q,p=0,h;
    char r;
    cin>>s>>n;
  	h=s.size();
    for(i=0;i<n;i++)
    {
        cin>>r>>q;
        if(r=='L')
        {
            p=(p+q)%s.size();
        }
        else
        {
          	q=h-q;
            p=(p+q)%s.size();
        }
        t.push_back(s[p]);
    }
    //cout<<t;
    
    for(i=0;i<=h-n;i++)
    {
        vector<ll>b(26,0);
        vector<ll>a(26,0);
        for(j=0;j<n;j++)
        {
            b[t[j]-97]++;
            a[s[i+j]-97]++;
        }
        p=0;
    //    cout<<","<<p<<"'";
        for(j=0;j<26;j++)
        {
            if(a[j]==b[j])
            {
                p++;
             //   cout<<(j+1)<<"*";
            }
        }
        if(p==26)   break;
    }
    if(p==26)
        cout<<"YES";
    else
        cout<<"NO";
   // cout<<t<<":"<<p;
}
