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

    vll a(n);
    vll b(n);

    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    ll ans = 0;
    ll run = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (b[i] == a[i + 1])
            run += 2;
        else
            run++;

        if (a[i] == b[i + 1])
            run += 2;
        else
            run++;
    }

    if (b[n - 1] == a[n - 1])
        run += 2;
    else
        run++;

    ans = max(ans, run);
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] == b[i])
            run += 2;
        else
            run++;

        if (a[i] == b[i + 1])
            run -= 2;
        else
            run--;
        ans = max(ans, run);
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