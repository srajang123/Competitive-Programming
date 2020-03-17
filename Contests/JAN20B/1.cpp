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
    ll s, i, j, k, p = 0, q = 0, c = 1;
    vector<ll> a(3);
    cin >> s;
    for (i = 0; i < 3; i++)
        cin >> a[i];
    for (i = 0; i < 3; i++)
    {
        if (a[i] + p > s)
        {
            c++;
            p = 0;
        }
        p += a[i];
    }
    cout << c << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}