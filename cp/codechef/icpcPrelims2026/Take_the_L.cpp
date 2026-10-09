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

struct L
{
    ll x;
    ll y;
};

void solve()
{
    ll n;
    cin >> n;

    vector<L> v(n);
    for (auto &a : v)
        cin >> a.x >> a.y;

    ranges::sort(v, [](const L &a, const L &b)
                 { return a.x < b.x; });

    ll cnt = 0;
    for (int i = 1; i < n; ++i)
        if (v[i].y < v[i - 1].y)
            cnt++;

    bool a = (cnt <= 1);

    ranges::sort(v, [](const L &a, const L &b)
                 { return a.y < b.y; });

    cnt = 0;
    for (int i = 1; i < n; ++i)
        if (v[i].x < v[i - 1].x)
            cnt++;

    bool b = (cnt <= 1);

    if (a || b)
        cout << "YES" << endl;
    else

        cout << "NO" << endl;
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