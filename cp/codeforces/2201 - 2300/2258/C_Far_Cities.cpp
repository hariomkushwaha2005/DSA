#include <bits/stdc++.h>
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

    int res;
    ll d = 1, a = 2;
    for (int i = 2; i <= n; ++i)
    {
        while (d + 1 < n)
        {
            cout << "?" << " " << 1 << " " << i << " " << d + 1 << endl;
            cin >> res;
            if (res == -1)
                exit(0);
            if (res)
            {
                d += 1;
                a = i;
            }
            else
                break;
        }
    }
    ll b = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i == a)
            continue;

        while (d + 1 < n)
        {
            cout << "?" << " " << a << " " << i << " " << d + 1 << endl;
            cin >> res;
            if (res == -1)
                exit(0);
            if (res)
            {
                d += 1;
                b = i;
            }
            else
                break;
        }
    }
    cout << "!" << " " << a << " " << b << " " << d << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}