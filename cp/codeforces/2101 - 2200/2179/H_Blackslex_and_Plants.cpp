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
    int n, q;
    cin >> n >> q;

    vector<vector<ll>> D(18, vector<ll>(n, 0));
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        for (int j = 0; j < 18; j++)
        {
            int st = l - 1 + (1 << j);
            if (st > r)
                break;

            ll ft = (1LL << 2 * j), c = (1LL << (2 * j + 1)), gap = (1 << (j + 1));
            D[j][st] += ft;
            if (st + gap < n)
                D[j][st + gap] += (c - ft);
            ll m = (r - st) / gap, lt = ft + c * m, et = st + m * gap;
            if (et + gap < n)
                D[j][st + (m + 1) * gap] -= (lt + c);
            if (et + 2 * gap < n)
                D[j][st + (m + 2) * gap] += (lt);
        }
    }
    for (int i = 0; i < 18; i++)
    {
        int gap = (1 << (i + 1));
        for (int j = gap; j < n; j++)
        {
            D[i][j] += D[i][j - gap];
        }
    }
    for (int i = 0; i < 18; i++)
    {
        int gap = (1 << (i + 1));
        for (int j = gap; j < n; j++)
        {
            D[i][j] += D[i][j - gap];
        }
    }

    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = 0; j < 18; j++)
        {
            sum += D[j][i];
        }
        cout << sum << " ";
    }
    cout << endl;
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