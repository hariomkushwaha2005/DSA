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

    ll last1 = INT_MAX, last2 = INT_MAX;
    ll curr;
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> curr;
        if (curr <= last1)
            last1 = curr;
        else if (curr <= last2)
            last2 = curr;
        else
        {
            last1 = last2;
            last2 = curr;
            cnt++;
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