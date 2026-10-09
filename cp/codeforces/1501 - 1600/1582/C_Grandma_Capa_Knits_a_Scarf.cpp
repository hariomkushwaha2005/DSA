#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int func(string &s, char c)
{
    int n = s.length();
    int cnt = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            if (s[l] == c)
            {
                cnt++;
                l++;
            }
            else if (s[r] == c)
            {
                cnt++;
                r--;
            }
            else
                return INT_MAX;
        }
    }
    return cnt;
}

void solve()
{
    // Your logic goes here
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = INT_MAX;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        ans = min(func(s, c), ans);
    }
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans << endl;
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