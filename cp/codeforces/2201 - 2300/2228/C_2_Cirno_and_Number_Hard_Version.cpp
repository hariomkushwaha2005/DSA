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
    ll a, n;
    cin >> a >> n;

    vi v(n);
    for (auto &x : v)
        cin >> x;

    if (n == 1 && v[0] == 0)
    {
        cout << a << endl;
        return;
    }

    ll ans = LLONG_MAX;
    ll num = v[0] == 0 ? v[1] : v[0];
    while (num < a)
    {
        num = num * 10 + v[0];
        ans = min(ans, abs(a - num));
    }

    num = 0;
    while (num < a)
    {
        num = num * 10 + v[n - 1];
        ans = min(ans, abs(a - num));
    }

    num = 0;
    string s = to_string(a);
    int i = 0;
    while (i < s.size())
    {
        ll num1 = num;
        for (auto &it : v)
        {
            if (it > s[i] - '0')
            {
                num1 = num1 * 10 + it;
                ans = min(ans, abs(a - num1));
                while (num1 < a)
                {
                    num1 = num1 * 10 + v[0];
                    ans = min(ans, abs(a - num1));
                }
                break;
            }
        }
        num1 = num;
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[j] < s[i] - '0')
            {
                num1 = num1 * 10 + v[j];
                ans = min(ans, abs(a - num1));
                while (num1 < a)
                {
                    num1 = num1 * 10 + v[n - 1];
                    ans = min(ans, abs(a - num1));
                }
                break;
            }
        }
        bool match = false;
        for (auto &it : v)
        {
            if (it == s[i] - '0')
            {
                num = num * 10 + it;
                ans = min(ans, abs(a - num));
                match = true;
                break;
            }
        }
        if (!match)
        {
            break;
        }
        i++;
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