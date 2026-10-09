#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    // Your logic goes here
    ll n;
    cin >> n;

    string a, b;
    cin >> a;
    cin >> b;

    vector<int> c;
    ll d = 0;
    ll e = 0;
    ll f = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i])
            e++;
        else
            e--;

        if (a[i] == '1')
            d++;
        else
            d--;

        if (d == 0)
        {
            ll g = i - f;
            if (abs(e) != g)
            {
                cout << "NO" << endl;
                return;
            }
            e = 0;
            f = i;
        }
    }
    if (e == n - 1 - f)
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