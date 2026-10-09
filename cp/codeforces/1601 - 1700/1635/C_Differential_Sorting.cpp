#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int n;
    cin >> n;

    for (int i; i < n; ++i)
        cin >> v[i];

    for (int i = n - 2; i >= 0; --i)
    {
        if (v[i + 1] < v[i])
        {
            cout << -1 << endl;
            return;
        }
        else if (v[i + 1] >= 0)
        {
            cout << i << endl;
            for (int j = 0; j < i; ++j)
            {
                cout << j + 1 << " " << i + 1 << " " << i + 2 << endl;
            }
            return;
        }
    }
    cout << 0 << endl;
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