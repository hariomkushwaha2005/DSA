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
    ll n;
    cin >> n;

    ll a, b;
    cin >> a;
    ll cnt = 0;
    for (int i = 2; i < n; ++i)
    {
        ll x;
        cin >> x;
        cnt += (x == 0);
    }
    cin >> b;

    if (a + b == 0)
        cout << 0 << endl;
    else if (a + b == 1 && cnt > 0)
        cout << 1 << endl;
    else if (a + b == 2 && cnt > 1)
        cout << 2 << endl;
    else
        cout << -1 << endl;
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