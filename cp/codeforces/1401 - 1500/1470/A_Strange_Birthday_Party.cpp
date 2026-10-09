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
    ll n, m;
    cin >> n >> m;

    vll a(n), b(m);
    for (auto &x : a)
    {
        cin >> x;
        x--;
    }
    for (auto &y : b)
        cin >> y;

    sort(all(a));

    ll ans = 0;
    ll j = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] < j)
            ans += b[a[i]];
        else
        {
            ans += b[j];
            j++;
        }
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