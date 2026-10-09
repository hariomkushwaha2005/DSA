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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll cntg = 0;
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'G')
            cntg++;

        if (cntg > k + 1)
        {
            if (s[i] == 'G')
                cnt++;
            else
                cnt += 2;
        }
    }
    if (cnt > k + 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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