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

void perms(int n, string s, vector<string> &ans)
{
    if (s.size() == n)
    {
        ans.push_back(s);
        return;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (freq[i] > 0)
        {
            freq[i]--;
            perms(n, s + (char)('a' + i), ans);
            freq[i]++;
        }
    }
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    for (char c : s)
        freq[c - 'a']++;

    vector<string> ans;

    perms(n, "", ans);

    cout << ans.size() << endl;
    for (string &a : ans)
        cout << a << endl;
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