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

    int n = s.size();

    ll cnt = 0, maxx = 0;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
            cnt = 0;
        maxx = max(maxx, cnt);
    }

    cout << maxx + 1 << endl;
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