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
    long long n, k, x;
    cin >> n >> k >> x;

    vll v(n);
    for (auto &x : v)
        cin >> x;
    sort(all(v));

    vector<long long> arr(n, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        arr[i] = max(0LL, (v[i + 1] - v[i] - 1) / x);
    }

    int cnt = 1;
    sort(all(arr));
    for (long long num : arr)
    {
        if (num <= k)
            k -= num;
        else
            cnt++;
    }
    cout << cnt << endl;
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