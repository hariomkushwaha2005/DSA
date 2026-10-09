#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << "YES" << endl;
        return;
    }

    if (n < 3)
    {
        cout << "NO" << endl;
        return;
    }
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i & 1)
        {
            if (s[i] == '1')
                cnt1++;
            else
                cnt1--;
        }
        else
        {
            if (s[i] == '1')
                cnt2++;
            else
                cnt2--;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (i & 1)
        {
            if (t[i] == '1')
                cnt1--;
            else
                cnt1++;
        }
        else
        {
            if (t[i] == '1')
                cnt2--;
            else
                cnt2++;
        }
    }

    if(cnt1 == 0 && cnt2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
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