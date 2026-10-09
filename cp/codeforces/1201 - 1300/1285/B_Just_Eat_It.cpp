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

    ll st = 0;
    ll sum = 0;
    ll runsum = 0, maxsum = 0;
    ll x;
    ll len = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        sum += x;
        runsum += x;
        if (runsum <= 0)
            st = i + 1;
        if (maxsum < runsum)
        {
            len = i - st + 1;
            maxsum = runsum;
        }
    }
    if(maxsum > sum || (maxsum == sum && len < n)) cout << "NO" << endl;
    else cout << "YES" << endl;
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