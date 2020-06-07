#include <bits/stdc++.h>
#include <string.h>
using namespace std;
//srajang_123
 
#define PEACE std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DECIMAL(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define hell 1000000007
#define PI 3.14159265358979323844
#define mp make_pair
#define pb push_back
#define fi first 
#define se second
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define endl "\n"
#define maxc(v) max_element(all(v))
#define minc(v) min_element(all(v))
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
#define initarr(a,n,x) for (int i=0;i<n;++i) a[i]=x
#define rep(i, n)    for(int i = 1; i <= (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define sz(a) (int)a.size()
#define sl(a) (int)a.length()
#define invect(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.pb(tmp);commands}
#define inset(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.insert(tmp);commands}
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
 
#define ll long long int
typedef long double ld;
#define pii std::pair<int, int> 
#define pll std::pair<ll, ll>  
#define vi vector<int>  
#define vvi vector<vi > 
#define vii vector<pii >
#define MOD 998244353
#define N 10000005

double n,m,k,x,y;

bool sortbysec(const pair<double,int> &a, 
              const pair<double,int> &b) 
{ 
    return (a.second < b.second); 
} 

void solve()
{
  cin >> n;
  stack <char> st;
  string s,ans="";
  ll i=0;
  while(cin >> s)
  {
    if(i!=0 and st.empty() and (s=="pair" or s=="int")){
      cout << "Error occurred" << endl;
      return;
    }
    if(s=="pair")
    {
      ans += "pair<";
      st.push('<');
    }
    else
    {
      if(!st.empty() and st.top()=='<')
      {
        ans += "int,";
        st.pop();
        st.push(',');
      }
      else if(!st.empty() and st.top()==',')
      {
        if(!st.empty() and st.top()==',')
        {
          ans += "int>";
          st.pop();
        }
        while(!st.empty() and st.top()==',')
        {
          ans+= ">";
          st.pop();
        }
        if(!st.empty() and st.top()=='<')
        {
          ans+= ',';
          st.pop();
          st.push(',');
        }
      }
    }
    i++;
  }
  
  if(i==1 and s == "int")
    cout << "int" << endl;
  else if(!st.empty() or ans=="")
    cout << "Error occurred" << endl;
  else 
    cout << ans << endl;
    
}

int main(){
  
  PEACE
  
  ll t=1;
  while(t--)
  {   
   solve();
  }
 
  return 0;
} 