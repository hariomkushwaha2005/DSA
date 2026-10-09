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

    string s;
    cin >> s;

    bool plus = 0;
    if (s[0] == '(')
        plus = 1;

    ll cnt = 0;
    bool type = 0;
    for (char c : s)
    {
        if (c == '(')
            cnt++;
        else
            cnt--;

        if ((plus && cnt < 0) || (!plus && cnt > 0))
            type = 1;
    }

    if (cnt != 0)
    {
        cout << -1 << endl;
        return;
    }

    if (!type)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }

    cout << 2 << endl;
    int i = 0, j = 0;
    for (; i < n; ++i)
    {
        if (s[i] == '(')
        {
            while (s[j] != ')')
                ++j;
            s[i] = '1';
            s[j] = '1';
            ++j;
        }
        else
        {
            while (s[j] != '(')
                ++j;
            s[i] = '2';
            s[j] = '2';
            ++j;
        }
    }

    for (char c : s)
        cout << c << " ";
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