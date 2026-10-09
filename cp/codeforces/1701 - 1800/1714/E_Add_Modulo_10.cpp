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

    ll one = 0, two = 0, three = 0;
    ll equal = 1;
    ll z;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        ll y = x % 10;
        ll val = y == 5 ? x + 5 : x;

        x /= 10;
        if (y == 1 || y == 2 || y == 4 || y == 8)
        {
            if (x & 1)
                two++;
            else
                one++;
        }
        else if (y == 0 || y == 5)
            three++;
        else
        {
            if (x & 1)
                one++;
            else
                two++;
        }
        if (i > 0 && z == val)
            equal++;
        z = val;
    }

    if ((three == n && equal == n) || two == n || one == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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