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

    vll v;
    vll b;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '3')
            continue;
        else if (s[i] == '2')
        {
            if (!v.empty())
            {
                v.pop_back();
                b.push_back(i + 1);
            }
        }
        else
            v.push_back(i + 1);
    }

    while (!b.empty())
    {
        v.push_back(b.back());
        b.pop_back();
    }

    ranges::sort(v);

    cout << v.size() << endl;
    for (auto &a : v)
        cout << a << " ";
    cout << endl;
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