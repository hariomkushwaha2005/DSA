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

ll dfs(int i, int x, int y, string &s, vector<vll> &vis)
{
    if (x == 7 && y == 1)
        return i == 48;

    if (i == 48)
        return 0;

    if (vis[x][y - 1] && vis[x][y + 1] && !vis[x - 1][y] && !vis[x + 1][y])
        return 0;

    if (vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1])
        return 0;

    ll val = 0;
    vis[x][y] = 1;

    if (s[i] == 'D' || s[i] == '?')
        if (!vis[x + 1][y])
            val += dfs(i + 1, x + 1, y, s, vis);

    if (s[i] == 'L' || s[i] == '?')
        if (!vis[x][y - 1])
            val += dfs(i + 1, x, y - 1, s, vis);

    if (s[i] == 'R' || s[i] == '?')
        if (!vis[x][y + 1])
            val += dfs(i + 1, x, y + 1, s, vis);

    if (s[i] == 'U' || s[i] == '?')
        if (!vis[x - 1][y])
            val += dfs(i + 1, x - 1, y, s, vis);

    vis[x][y] = 0;
    return val;
}

void solve()
{
    string s;
    cin >> s;

    vector<vll> vis(9, vll(9, 0));
    for (int i = 0; i < 9; ++i)
    {
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }

    cout << dfs(0, 1, 1, s, vis) << endl;
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