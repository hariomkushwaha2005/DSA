#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    vi v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = i + 1;
        int j = v[i] - x % v[i];
        j = j + (x - j + v[i]) / v[i] * v[i];
        while (j <= n)
        {
            if (1LL * v[i] * v[j - 1] == x + j)
                cnt++;
            j += v[i];
        }
    }

    cout << cnt << endl;
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