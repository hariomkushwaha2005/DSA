#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

// #define endl '\n'
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

    n = n << 1;
    int ans = n;
    int x;
    for (int i = 1; i <= n - 4; i += 2)
    {
        cout << "? " << i << " " << i + 1 << endl;
        cin >> x;
        if (x == 1)
        {
            ans = i;
        }
    }
    cout << "? " << n - 3 << " " << n - 2 << endl;
    cin >> x;
    if (x == 1)
    {
        ans = n - 3;
    }
    cout << "? " << n - 3 << " " << n - 1 << endl;
    cin >> x;
    if (x == 1)
    {
        ans = n - 3;
    }
    cout << "? " << n - 2 << " " << n - 1 << endl;
    cin >> x;
    if (x == 1)
    {
        ans = n - 2;
    }
    cout << "! " << ans << endl;
}

int main()
{
    // fast_io();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}