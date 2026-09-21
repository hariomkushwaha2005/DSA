#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    if (n == 2)
    {
        cout << "11" << endl;
        return;
    }

    string s(n, '0');
    if ((n - 2) % 6 == 0)
    {
        s[0] = '1';
        s[(n - 2) / 3 + 1] = '1';
        s[2 * (n - 2) / 3 + 1] = '1';
    }
    else
    {
        ll x = (n - 2) / 3, y = (n - 1) / 3, z = n / 3;
        if (!(y & 1))
        {
            if (x & 1)
                swap(x, y);
            else
                swap(y, z);
        }
        s[x] = '1';
        s[x + y + 1] = '1';
    }

    cout << s << endl;
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