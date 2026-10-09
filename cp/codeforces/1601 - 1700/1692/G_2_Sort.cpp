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
    ll n, k;
    cin >> n >> k;

    ll last;
    cin >> last;
    ll cnt = 0, ans = 0;
    for (int i = 1; i < n; ++i)
    {
        ll cur;
        cin >> cur;
        if (last < (cur << 1))
            cnt++;
        else
        {
            ans += max(0LL, cnt - k + 1);
            cnt = 0;
        }
        last = cur;
    }
    ans += max(0LL, cnt - k + 1);
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