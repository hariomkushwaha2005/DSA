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

char help(int i, string &s)
{
    if (i == s.size() - 1)
        return s[i - 1] == 'a' ? 'b' : 'a';

    else if (s[i - 1] == 'a' || s[i + 1] == 'a')
    {
        if (s[i - 1] == 'b' || s[i + 1] == 'b')
            return 'c';
        else
            return 'b';
    }

    return 'a';
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
        {
            s[i] = help(i, s);
        }
    }
    cout << s << endl;
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