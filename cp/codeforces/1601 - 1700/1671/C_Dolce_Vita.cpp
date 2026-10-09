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

int v[200001];

void solve()
{
    // Your logic goes here
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    long long pre = 0;
    long long ans = 0;

    for (int i = 0; i < n; ++i)
    {
        pre += v[i];
        if (x < pre)
            break;
        int a = (x - pre) / (i + 1);
        ans += a + 1;
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