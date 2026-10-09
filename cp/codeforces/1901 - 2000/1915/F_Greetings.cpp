#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class sgt
{
    vll a;
    ll n;

public:
    sgt(ll z)
    {
        n = z;
        a.resize(2 * n, 0);
    }

    void update(ll idx)
    {
        idx += n;
        a[idx]++;
        for (idx >>= 1; idx > 0; idx >>= 1)
            a[idx]++;
    }

    ll query(ll l, ll r)
    {
        l += n;
        r += n;
        ll ans = 0;
        while (l < r)
        {
            if (l & 1)
                ans += a[l++];
            if (r & 1)
                ans += a[--r];
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> c(n);
    vll a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i].second >> c[i].first;
        a[i] = c[i].second;
    }

    sort(c.begin(), c.end());
    ranges::sort(a);

    for (int i = 0; i < n; ++i)
        c[i].second = lower_bound(a.begin(), a.end(), c[i].second) - a.begin();

    sgt sg(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += sg.query(c[i].second, n);
        sg.update(c[i].second);
    }
    cout << ans << endl;
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