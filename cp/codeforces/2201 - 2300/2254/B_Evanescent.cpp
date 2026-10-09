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

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll cnt = 1;
    ll single = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if (s[i] != s[i - 1] && s[i] != s[i + 1])
        {
            if (s[i - 1] == s[i + 1])
            {
                single = 2;
                break;
            }
            single = 1;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != s[i - 1])
            cnt++;
    }
    cout << cnt - single << endl;
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