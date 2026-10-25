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
    string s;
    cin >> s;
    int n = s.size();

    vector<ll> freq(26, 0);
    for (char c : s)
        freq[c - 'A']++;

    ll last = -1;
    string cur = "";
    for (int i = 0; i < n; ++i)
    {
        ll rem = n - i;
        bool inserted = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (j == last)
                continue;
            if (freq[j] > 0)
            {
                freq[j]--;
                ll maxx = 0;
                for (int k = 0; k < 26; ++k)
                    maxx = max(maxx, freq[k]);
                if (maxx <= (rem >> 1))
                {
                    last = j;
                    cur += (char)('A' + j);
                    inserted = 1;
                    break;
                }
                freq[j]++;
            }
        }
        if(!inserted) {
            cout << -1 << endl;
            return;
        }
    }
    cout << cur << endl;
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