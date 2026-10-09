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

void solve()
{
    ll n, k;
    cin >> n >> k;

    vll a;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ll y = x % k;

        if (y)
            a.push_back(k - y);
    }
    ranges::sort(a);
    if (a.size() == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll f = 1, val = a[0], cur = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[i - 1])
            cur++;
        else
            cur = 1;
        if (cur >= f)
        {
            f = cur;
            val = a[i];
        }
    }
    cout << (f - 1) * k + val + 1 << endl;
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