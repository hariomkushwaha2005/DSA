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

    vll r(n);
    vector<vll> c(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        cin >> r[i];

        x--;
        if (x >= 0)
            c[x].push_back(i);
    }

    vll del;
    for (int i = 0; i < n; ++i)
    {
        if (r[i] == 1)
        {
            bool d = 1;
            for (auto j : c[i])
            {
                if (r[j] == 0)
                {
                    d = 0;
                    break;
                }
            }
            if (d)
                del.push_back(i);
        }
    }
    if (del.size() == 0)
        cout << -1 << endl;
    else
    {
        for (auto i : del)
            cout << i + 1 << " ";
        cout << endl;
    }
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