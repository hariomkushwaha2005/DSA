#pragma GCC optimize("O3,unroll-loops")

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
    int n, s;
    cin >> n >> s;

    vi v(n);
    vector<int> ones;
    ones.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
            ones.push_back(i);
    }

    int sum = ones.size() - 1;
    int target = sum - s;
    if (target < 0)
    {
        cout << -1 << endl;
        return;
    }

    ones.push_back(n);
    int ans = INT_MAX;
    int x = 0;
    while (x <= target)
    {
        int l = ones[target - x];
        int r = ones[sum + 1 - x];
        ans = min(ans, l + 1 + n - r);
        x++;
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