#include <bits/stdc++.h>
using namespace std;
#define sort(a) sort(a.begin(), a.end())
#define ll long long

ll pow(ll a, ll b)
{
    return a;
}
ll pow(ll a, ll b, ll m)
{
    return a;
}

void solve()
{
    ll b, c = 1, d, e, n, i, j, k, a;
    cin >> n >> a;
    ll s = a;
    k = 2 * pow(10, n);
    k=k+a;
    cout << k << "\n";
    cout << flush;
    cin >> b;
    c = pow(10, n);//-b;
    c-=b;
    s += b + c;
    cout << c << "\n";
    cout << flush;
    cin >> d;
    e = pow(10, n);//-d;
    e-=d;
    s += d + e;
    cout << e << "\n";
    cout << flush;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll k;
        solve();
        cin >> k;
        if (k == -1)
            break;
    }
}
