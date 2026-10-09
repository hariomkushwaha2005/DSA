#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n;
    cin >> n;

    int ml = __lg(n) + 1;
    vector<vll> bit(n, vll(ml));

    for (int i = 0; i < n; ++i)
        cin >> bit[i][0];

    for (int j = 1; j < ml; ++j)
        for (int i = 0; i + (1 << j) <= n; ++i)
            bit[i][j] = bit[i][j - 1] & bit[i + (1 << (j - 1))][j - 1];

    auto query = [&](ll l, ll r)
    {
        ll j = __lg(r - l + 1);
        return bit[l][j] & bit[r - (1 << j) + 1][j];
    };

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, k;
        cin >> l >> k;

        l--;
        if (bit[l][0] < k)
        {
            cout << -1 << " ";
            continue;
        }
        ll low = l, high = n - 1, ans = l;
        while (low <= high)
        {
            ll mid = low + ((high - low) >> 1);
            if (query(l, mid) >= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << ans + 1 << " ";
    }
    cout << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}