#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int i = 0; i + k < n; ++i)
    {
        if (s[i + k] == '?')
            s[i + k] = s[i];
        else if (s[i] == '?')
            s[i] = s[i + k];
        else if (s[i + k] != s[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = n - 1 - k; i >= 0; --i)
    {
        if (s[i] == '?')
            s[i] = s[i + k];
        else if (s[i + k] == '?')
            s[i + k] = s[i];
        else if (s[i + k] != s[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    ll cnt = 0;
    ll c = 0;
    for (int i = 0; i < k; ++i)
    {
        if (s[i] == '1')
            cnt++;
        else if (s[i] == '?')
            c++;
        else
            cnt--;
    }

    if (c >= abs(cnt))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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