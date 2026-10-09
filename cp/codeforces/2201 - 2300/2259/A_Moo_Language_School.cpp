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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll ans = 0;
    for (int i = 0; i < n; i += k)
    {
        ll cnt = 0;
        for (int j = 0; j < k; ++j)
        {
            if (s[i + j] == '0')
            {
                cnt++;
                break;
            }
        }
        ans += 1 - cnt;
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