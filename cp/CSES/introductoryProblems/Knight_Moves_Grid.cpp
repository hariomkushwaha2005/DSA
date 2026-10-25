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
    ll n;
    cin >> n;

    vector<vll> v(n, vll(n, INT_MAX));
    queue<pair<ll, ll>> q;
    v[0][0] = 0;
    q.push({0, 0});
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (v[nx][ny] > v[x][y] + 1)
                {
                    v[nx][ny] = v[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
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