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

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        v[i] = {x, 0};
    }

    for (int i = 1; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;

        --x;
        --y;

        v[x] = {v[x].first, v[x].second + 1};
        v[y] = {v[y].first, v[y].second + 1};
    }

    ranges::sort(v);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += v[i].first;
        v[i] = {v[i].first, v[i].second - 1};
    }

    cout << sum << " ";
    while (!v.empty())
    {
        while (!v.empty() && v.back().second == 0)
            v.pop_back();

        if (v.empty())
            break;

        sum += v.back().first;
        v.back() = {v.back().first, v.back().second - 1};
        cout << sum << " ";
    }
    cout << endl;
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