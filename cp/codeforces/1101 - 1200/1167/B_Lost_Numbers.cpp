#include <bits/stdc++.h>
// #define endl '\n'

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
    set<ll> a = {4, 8, 15, 16, 23, 42};
    vll v(6);

    ll x;
    cout << "?" << " " << 1 << " " << 2 << endl;
    cin >> x;

    ll y;
    cout << "?" << " " << 2 << " " << 3 << endl;
    cin >> y;

    for (auto i : a)
    {
        if (x % i == 0 && y % i == 0 && x / i != y / i && x / i != i && y / i != i && a.find(x / i) != a.end() && a.find(y / i) != a.end())
        {
            v[1] = i;
            v[0] = x / i;
            v[2] = y / i;
        }
    }

    cout << "?" << " " << 4 << " " << 5 << endl;
    cin >> x;

    cout << "?" << " " << 5 << " " << 6 << endl;
    cin >> y;

    for (auto i : a)
    {
        if (x % i == 0 && y % i == 0 && x / i != y / i && x / i != i && y / i != i && a.find(x / i) != a.end() && a.find(y / i) != a.end())
        {
            v[4] = i;
            v[3] = x / i;
            v[5] = y / i;
        }
    }

    cout << "!" << " ";
    for (auto i : v)
        cout << i << " ";

    cout << endl;
}

int main()
{
    fast_io();

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}