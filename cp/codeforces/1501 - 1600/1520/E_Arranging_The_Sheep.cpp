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

    ll tot = count(s.begin(), s.end(), '*');
    int i = 0, j = n - 1;
    while (s[i] == '.')
        ++i;
    while (s[j] == '.')
        --j;

    ll a = 0, b = 0;
    for (int k = i; k <= j; ++k)
    {
        if (s[k] == '*')
            ++a;

        else
            b += min(tot - a, a);
    }

    cout << b << endl;
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