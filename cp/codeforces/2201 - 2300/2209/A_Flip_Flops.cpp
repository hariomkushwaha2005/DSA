#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    ll n, c, k;
    cin >> n >> c >> k;

    vll monsters(n);

    for (ll &combatPower : monsters)
    {
        cin >> combatPower;
    }

    sort(all(monsters));

    for (int i = 0; i < n; ++i)
    {
        if (monsters[i] > c)
            break;
        if (k > 0)
        {
            ll inc = min(k, c - monsters[i]);
            monsters[i] += inc;
            k -= inc;
        }
        c += monsters[i];
    }
    cout << c << endl;
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