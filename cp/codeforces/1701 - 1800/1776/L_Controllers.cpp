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

    string s;
    cin >> s;

    ll plus = 0;
    for (auto c : s)
    {
        if (c == '+')
            plus++;
    }

    ll minus = n - plus;

    ll q;
    cin >> q;

    while (q--)
    {
        ll a, b;
        cin >> a >> b;

        if (a == b)
        {
            if (plus == minus)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        if (a > b)
            swap(a, b);

        ll minplus = a * plus;
        ll minminus = a * minus;
        ll maxplus = b * plus;
        ll maxminus = b * minus;

        if (!(minplus > maxminus || minminus > maxplus) && (minplus - minminus) % (b - a) == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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