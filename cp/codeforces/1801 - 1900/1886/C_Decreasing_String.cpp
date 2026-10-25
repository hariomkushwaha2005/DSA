#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    string s;
    cin >> s;

    ll pos;
    cin >> pos;

    ll n = s.size();

    ll l = 0, h = n - 1;
    while (l <= h)
    {
        ll mid = (l + h) >> 1;
        ll a = mid * n - (mid * (mid - 1) >> 1);

        if (a < pos)
            l = mid + 1;
        else
            h = mid - 1;
    }

    pos -= h * n - (h * (h - 1) >> 1);
    string b;
    ll cnt = 0;
    int i = 0;
    for (; i < n; ++i)
    {
        if (cnt == h)
            break;
        while (!b.empty() && b.back() > s[i] && cnt < h)
        {
            cnt++;
            b.pop_back();
        }
        b += s[i];
    }
    if (pos <= b.size())
        cout << b[pos - 1];
    else
    {
        pos -= b.size();
        cout << s[i + pos - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}