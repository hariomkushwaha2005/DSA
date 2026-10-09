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
    ll n, m;
    cin >> n >> m;

    vll a(n, 0);
    ll t = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        while (x % 10 == 0)
        {
            a[i]++;
            x /= 10;
        }
        while (x > 0)
        {
            t++;
            x /= 10;
        }
    }
    sort(all(a));
    for (int i = n - 2; i >= 0; i -= 2)
    {
        t += a[i];
    }

    if(t > m) cout << "Sasha" <<endl;
    else cout << "Anna" << endl;
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