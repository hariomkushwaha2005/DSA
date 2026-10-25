#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, k;
    cin >> n >> k;

    vll v(n);
    for (auto &i : v)
        cin >> i;

    ll pre = 0;
    vector<vll> a(k);
    a[0].push_back(-1);
    for (int i = 0; i < n; ++i)
    {
        pre += v[i];
        a[pre % k].push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ll sz = a[i].size();
        for (int j = 0; j < sz - 1; ++j)
        {
            ll l = j + 1, h = sz - 1;
            while (l <= h)
            {
                ll mid = (l + h) / 2;
                if (a[i][mid] - a[i][j] <= k)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            ans += (sz - l);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}