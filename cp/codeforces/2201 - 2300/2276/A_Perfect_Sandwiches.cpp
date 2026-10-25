#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll a, b;
    cin >> a >> b;

    ll ans = a - b;
    ans = min(ans, min(a, b));
    
    if (ans < 1)
        cout << -1 << endl;
    else
        cout << ans << endl;
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