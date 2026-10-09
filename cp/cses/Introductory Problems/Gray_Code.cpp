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

vector<vector<string>> v(16);

int freq[26];
void solve()
{
    ll n;
    cin >> n;

    n--;
    for (auto &s : v[n])
    {
        cout << s << endl;
    }
}

int main()
{
    fast_io();
    v[0].push_back("0");
    v[0].push_back("1");
    for (int i = 1; i < 16; ++i)
    {
        for (int j = 0; j < v[i - 1].size(); ++j)
            v[i].push_back('0' + v[i - 1][j]);
        for (int j = v[i - 1].size() - 1; j >= 0; --j)
            v[i].push_back('1' + v[i - 1][j]);
    }
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}