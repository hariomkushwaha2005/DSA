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

    string s;
    cin >> s;

    if (s[0] == '1')
    {
        int cnt = 0;
        for (auto c : s)
            if (c == '0')
                cnt++;
        cout << cnt << endl;
        return;
    }

    vll zero(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        zero[i] = zero[i + 1];
        if (s[i] == '0')
            zero[i]++;
    }

    vll one(n, 0);
    one[0] += (s[0] == '1');
    for (int i = 1; i < n; ++i)
    {
        one[i] = one[i - 1];
        if (s[i] == '1')
            one[i]++;
    }

    ll ans = LLONG_MAX;
    for (int i = 1; i < n; ++i)
        ans = min(ans, zero[i] + one[i - 1]);

    // ans = min(ans, zero[0]);
    ans = min(ans, one[n - 1]);
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