/*
Let's play the following game with two natural numbers (positive integers): Say, the two numbers are 5 and 6 and display them sorted as below in column A. We then spell the numbers and display them in column B. The spellings are then sorted and displayed in column C while column D displays the numerals corresponding to the sorted spellings:

Column A: Sorted numerals

Column B: Spelt numerals

Column C: Sorted Spelt numerals

Column D: Numerals corresponding to sorted spellings
Note that the numbers converge when the spelled order breaks from the numeric order. Write a program to accept two natural numbers n1 and n2, perform the above calculations and output the "converged" number. 
utput "Out of bounds" if any number exceeds 99,999 during calculations.

(Note: If the input numbers are the same, we would take the output to be that number itself.)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string>one;
vector<string>ten;
vector<string>ken;
vector<string>thousan;
void init()
{
    one.push_back("One");
    one.push_back("Two");
    one.push_back("Three");
    one.push_back("Four");
    one.push_back("Five");
    one.push_back("Six");
    one.push_back("Seven");
    one.push_back("Eight");
    one.push_back("Nine");
    
    ken.push_back("Eleven");
    ken.push_back("Twelve");
    ken.push_back("Thirteen");
    ken.push_back("Fourteen");
    ken.push_back("Fifteen");
    ken.push_back("Sixteen");
    ken.push_back("Seventeen");
    ken.push_back("Eighteen");
    ken.push_back("Nineteen");
    
    ten.push_back("Ten");
    ten.push_back("Twenty");
    ten.push_back("Thirty");
    ten.push_back("Fourty");
    ten.push_back("Fifty");
    ten.push_back("Sixty");
    ten.push_back("Seventy");
    ten.push_back("Eighty");
    ten.push_back("Ninety");
    
   // ten.push_back("");
}
vector<string> convert(ll n)
{
    ll p=0,q=0,r=0,i;
    p=n%100;
    n/=100;
    q=n%10;
    n/=10;
    r=n;
    vector<string>s;
    if(p>10 && p<20)
    {
        s.push_back(ken[p-11]);
    }
    else
    {
    if(p%10!=0)
    {
        s.push_back(one[p%10-1]);
    }
    p/=10;
    if(p!=0)
    {
        s.push_back(ten[p-1]);
    }
    }
    if(q!=0)
    {
        s.push_back("hundred");
        s.push_back(one[q-1]);
    }
    if(r!=0)
    {
        s.push_back("thousand");
        if(r>10 && r<20)
        {
            s.push_back(ken[r-11]);
        }
        else
        {
        if(r%10!=0)
            s.push_back(one[r%10-1]);
        r/=10;
        if(r!=0)
        {
            s.push_back(ten[r-1]);
        }
        }
    }/*
    string mt;
    for(i=s.size()-1;i>=0;i--)
    {
        mt.append(s[i]);
        mt.append(" ");
    }*/
    return s;
}
int rconvert(string sg)
{
  return 0;  
}
string my(vector<string>brahma)
{
    string mt;
    for(ll i=brahma.size()-1;i>=0;i--)
    {
        mt.append(brahma[i]);
        mt.append(" ");
    }
    return mt;
}
int main()
{
    ll n,m,i,j,k,c,p=0,q=0,r=0,z=0;
    cin>>n>>m;
    init();
  if(m<n)
  {
      i=m;
      m=n;
      n=i;
  }
  {
    while(n!=m)
    {
    vector<string>s1,s2,ss;
    if(n>99999 || m>99999)
    {
      z=1;
      break;
    }
    s1=convert(n);
    s2=convert(m);
    ss.push_back(my(s1));
    ss.push_back(my(s2));
    sort(ss.begin(),ss.end());
    if(ss[0]==my(s1))
    {
        p=n;
        q=m;
    }
    else
    {
        p=m;
        q=n;
    }
    n+=p;
    m+=q;
    if(n>99999 || m>99999)
    {
      z=1;
      break;
    }
    }
    if(z==1)
        cout<<"Out of bounds";
    else
        cout<<n;
}
}
