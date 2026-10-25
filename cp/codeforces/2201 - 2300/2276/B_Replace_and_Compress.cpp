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

    ll n = s.size();

    ll cnt = 1;
    bool one = 0;
    bool zero = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        if ((s[i - 1] == '0' && s[i + 1] == '0' && s[i] == '1') || (s[i - 1] == '1' && s[i + 1] == '1' && s[i] == '0'))
            one = 1;
        if ((s[i - 1] == '0' && s[i + 1] == '0' && s[i] == '0') || (s[i - 1] == '1' && s[i + 1] == '1' && s[i] == '1'))
            zero = 1;
    }
    cout << cnt + one + zero << endl;
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