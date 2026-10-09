#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()

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
    ll n, x, y;
    cin >> n >> x >> y;

    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        ll z;
        cin >> z;

        cnt += (z & 1);
    }

    cout << (((x ^ y ^ cnt) & 1) ? "Bob\n" : "Alice\n");
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