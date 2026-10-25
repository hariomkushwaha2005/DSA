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

    vll v(n);
    for (auto &i : v)
        cin >> i;

    ll pts = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            ll g = 0;
            for (int j = 0; j + i < n; ++j)
                g = gcd(g, abs(v[j] - v[j + i]));
            if (g != 1)
                pts++;
        }
    }

    cout << pts << endl;
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