#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vll a(n + 1, 0), b(m + 1, 0);

    ll cnt = 0;
    ll lst = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        if (x == 0)
            cnt = 0;
        else
        {
            cnt++;
            a[cnt]++;
        }
    }
    for (int i = n; i > 0; --i)
    {
        a[i] += lst;
        lst = a[i];
    }

    cnt = 0;
    lst = 0;
    for (int i = 0; i < m; ++i)
    {
        ll x;
        cin >> x;

        if (x == 0)
            cnt = 0;
        else
        {
            cnt++;
            b[cnt]++;
        }
    }
    for (int i = m; i > 0; --i)
    {
        b[i] += lst;
        lst = b[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (k % i == 0 && k / i <= m)
            ans += (a[i] * b[k / i]);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}