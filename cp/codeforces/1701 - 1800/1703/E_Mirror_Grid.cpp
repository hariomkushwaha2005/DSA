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
    // Your logic goes here
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }
    int x = 0;
    int ans = 0;
    while (x < (n + 1) / 2)
    {
        for (int i = x; i < n - x - 1; i++)
        {
            int zero = 0;
            if (v[x][i] == 0)
                zero++;
            if (v[i][n - 1 - x] == 0)
                zero++;
            if (v[n - 1 - x][n - 1 - i] == 0)
                zero++;
            if (v[n - 1 - i][x] == 0)
                zero++;

            if (zero == 2)
                ans += 2;
            else if (zero == 1 || zero == 3)
                ans++;
        }
        x++;
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