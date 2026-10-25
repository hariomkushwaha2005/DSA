#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

ll mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;

    ll n = s.size();

    vll a;
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'a')
            cnt++;

        if (s[i] == 'b' && cnt > 0)
        {
            a.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt > 0)
        a.push_back(cnt);

    ll val = 1;
    for (auto x : a)
        val = val * (x + 1) % mod;

    cout << val - 1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}