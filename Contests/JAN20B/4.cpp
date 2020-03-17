#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, t, i, j, k;
    cin >> n >> t;
    vector<ll> a(n), b(n, 0), c(n, 0), d(n, 0), e(n, 0);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            b[i] = 1;
            if (i < n - 1)
            {
                if (a[i] > a[i + 1])
                    c[i] = 1;
            }
        }
        if (a[i] < a[i - 1])
        {
            d[i] = 1;
            if (i < n - 1)
            {
                if (a[i] < a[i + 1])
                    e[i] = 1;
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        b[i] += b[i - 1];
        c[i] += c[i - 1];
        d[i] += d[i - 1];
        e[i] += e[i - 1];
    }
    while (t--)
    {
        ll l, r, p = 0, q = 0;
        cin >> l >> r;
        l--;
        r--;
        if (b[r] > b[r - 1])
            p++;
        if (d[r] > d[r - 1])
            q++;
        p += c[r] - c[l];
        q += e[r] - e[l];
        if (p == q)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
}