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

int freq[26];
void solve()
{
    string s;
    cin >> s;

    for (char c : s)
        freq[c - 'A']++;

    int n = s.size();
    if (n & 1)
        s[(n >> 1)] = '0';

    int j = 0;
    for (int i = 0; i < 26; ++i)
    {
        while (freq[i] > 1)
        {
            s[j] = 'A' + i;
            s[n - 1 - j] = 'A' + i;
            ++j;
            freq[i] -= 2;
        }
        if (freq[i] == 1)
        {
            if (s[(n >> 1)] == '0')
                s[(n >> 1)] = 'A' + i;
            else
            {
                cout << "NO SOLUTION" << endl;
                return;
            }
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