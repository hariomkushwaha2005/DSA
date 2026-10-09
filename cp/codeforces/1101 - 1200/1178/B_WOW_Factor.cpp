#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    string s;
    cin >> s;

    ll cnt = 0;
    vll v;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'o')
        {
            v.push_back(max(cnt - 1, 0LL));
            cnt = 0;
        }
        else
            cnt++;
    }
    v.push_back(max(cnt - 1, 0LL));

    int n = v.size();
    vll a(n);
    a[0] = 0;

    for (int i = 0; i < n - 1; ++i)
        a[i + 1] = v[i] + a[i];

    ll ans = 0;
    ll sum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        sum += v[i];
        ans += sum * a[i];
    }

    cout << ans << endl;
}

int main()
{
    fast_io();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}