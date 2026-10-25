#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n;
    cin >> n;

    vll x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    ranges::sort(x);
    ranges::sort(y);

    if (n & 1)
        cout << 1 << endl;
    else
        cout << (x[n / 2] - x[(n - 1) / 2] + 1) * (y[n / 2] - y[(n - 1) / 2] + 1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}