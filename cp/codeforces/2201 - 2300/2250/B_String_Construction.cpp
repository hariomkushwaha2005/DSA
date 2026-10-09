#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    ll n, k;
    cin >> n >> k;

    if (k > (n - 2))
    {
        cout << -1 << endl;
        return;
    }

    string s = "";
    for (int i = 0; i < k / 2 + 1; ++i)
        s += '0';
    for (int i = 0; i < (k - k / 2) + 1; ++i)
        s += '1';

    bool x = 0;
    for (int i = s.size(); i < n; ++i)
    {
        s += '0' + x;
        x = !x;
    }
    cout << s << endl;
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