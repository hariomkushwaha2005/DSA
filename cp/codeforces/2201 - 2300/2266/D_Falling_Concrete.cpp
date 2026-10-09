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

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vll b(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b[i] = x - (i + 1);
    }

    ranges::sort(b); 

    ll ans = 1;
    ll curr = 1;

    for (int i = 1; i < n; i++)
    {
        if (b[i] == b[i - 1])
        {
            continue;
        }

        if (b[i] == b[i - 1] + 1)
        {
            curr++;
        }
        else
        {
            curr = 1;
        }

        ans = max(ans, curr);
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