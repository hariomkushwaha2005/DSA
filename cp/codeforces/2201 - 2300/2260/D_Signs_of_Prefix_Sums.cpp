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

    if (s[0] == '0' || s.find("00") != string::npos)
    {
        cout << -1 << endl;
        return;
    }
    bool can_be_1 = (s.find("+-") == string::npos && s.find("-+") == string::npos);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && i % 2 == 0)
        {
            can_be_1 = false;
        }
    }

    if (can_be_1)
    {
        cout << 1 << endl;
        return;
    }

    if (s.find("+--+") != string::npos || s.find("-++-") != string::npos)
    {
        cout << 3 << endl;
        return;
    }

    cout << 2 << endl;
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