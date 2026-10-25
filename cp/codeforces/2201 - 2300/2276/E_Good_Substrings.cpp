#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

ll memotf(ll i, ll state, string &s, vector<vll> &dp)
{
    ll n = s.size();

    if (i >= n)
        return n;

    if (dp[i][state] != n + 1)
        return dp[i][state];

    ll ans = memotf(i + 1, state, s, dp);
    if (state == 0 && s[i] == '2')
        ans = memotf(i + 1, state + 1, s, dp);
    else if (state == 1 && s[i] == '0')
        ans = memotf(i + 1, state + 1, s, dp);
    else if (state == 2 && s[i] == '2')
        ans = memotf(i + 1, state + 1, s, dp);
    else if (state == 3 && s[i] == '5')
        ans = i;

    return dp[i][state] = ans;
}
ll memots(ll i, ll state, string &s, vector<vll> &dp)
{
    ll n = s.size();

    if (i >= n)
        return n;

    if (dp[i][state] != n + 1)
        return dp[i][state];

    ll ans = memots(i + 1, state, s, dp);

    if (state == 0 && s[i] == '2')
        ans = memots(i + 1, state + 1, s, dp);
    else if (state == 1 && s[i] == '0')
        ans = memots(i + 1, state + 1, s, dp);
    else if (state == 2 && s[i] == '2')
        ans = memots(i + 1, state + 1, s, dp);
    else if (state == 3 && s[i] == '6')
        ans = i;

    return dp[i][state] = ans;
}

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector<vll> dptf(n, vll(4, n + 1));
    vector<vll> dpts(n, vll(4, n + 1));
    memotf(0, 0, s, dptf);
    memots(0, 0, s, dpts);

    vll a(n + 1, 0);
    vll b(n);
    for (int i = 0; i < n; ++i)
    {
        b[i] = n - i;
        if (dptf[i][0] < dpts[i][0])
        {
            a[dptf[i][0]] += 1;
            a[dpts[i][0]] -= 1;
            b[i] -= (dpts[i][0] - dptf[i][0]);
        }
        if (i > 0)
            a[i] += a[i - 1];
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cnt += b[i];
        cout << cnt << " ";
        cnt -= (i + 1);
        cnt += a[i];
    }
    cout << endl;
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