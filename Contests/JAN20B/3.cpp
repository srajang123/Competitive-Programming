#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pow(ll a, ll b)
{
    return a;
}
ll power(ll a, ll b, ll m)
{
    return a;
}

void solve()
{
    ll n, m, i, j, k, l, c = 0, p, q,z=0,tt;
    cin >> n >> m;
    c = n * m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 1; i < n - 1; i++)
    {
        for (j = 1; j < m - 1; j++)
        {
            tt = i<j?i:j;
            l = j;
            k = i;
            map<ll, ll> b;
            q = 0;
            for (p = k - 1; p >= 0 && q == 0 && (2 * k - p < n); p--)
            {
                if (a[p][j] == a[2 * k - p][j])
                    b[k - p] += 1;
                else
                    q = 1;
                z++;
                if(z>=tt)break;
            }
            q = 0;
            z=0;
            for (p = l - 1; p >= 0 && q == 0 && (2 * l - p < m); p--)
            {
                if (a[i][p] == a[i][2 * l - p])
                    b[l - p] += 1;
                else
                    q = 1;
                if(z>=tt)break;
            }
            for (auto x : b)
            {
                if (x.second % 2 == 0)
                    c++;
                else
                    break;
            }
        }
    }
    cout << c << "\n";
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