#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

bool valid(string &s, int st, bool f)
{
    for (int i = st; i < s.size(); ++i)
    {
        if (s[i] == '?' || s[i] == '0' + f)
            int x;
        else
            return false;

        ++i;
        if (i == s.size())
            break;

        if (s[i] == '?' || s[i] == '0' + f)
            int x;
        else
            return false;

        f = !f;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    if (s[0] == '0')
    {
        ans += valid(s, 0, 0);
        ans += valid(s, 1, 1);
    }
    else if (s[0] == '1')
    {
        ans += valid(s, 0, 1);
        ans += valid(s, 1, 0);
    }
    else
    {
        ans += valid(s, 0, 0);
        ans += valid(s, 0, 1);
        ans += valid(s, 1, 0);
        ans += valid(s, 1, 1);
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