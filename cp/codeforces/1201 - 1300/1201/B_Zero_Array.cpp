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

    ll sum = 0, maxx = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        maxx = max(x, maxx);
        sum += x;
    }

    if (maxx > sum / 2 || sum & 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}