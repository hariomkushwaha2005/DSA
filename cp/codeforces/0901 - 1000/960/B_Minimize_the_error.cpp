#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, k, k1;
    cin >> n >> k >> k1;
    k += k1;

    vll a(n);
    for (auto &i : a)
        cin >> i;

    priority_queue<ll> pq;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        pq.push(abs(x - a[i]));
    }
    while (k > 0)
    {
        if (pq.top() == 0)
            break;
        ll z = pq.top();
        pq.pop();
        pq.push(z - 1);
        k--;
    }
    if (k & 1)
    {
        cout << 1 << endl;
        return;
    }
    ll ans = 0;
    while (!pq.empty())
    {
        ans += pq.top() * pq.top();
        pq.pop();
    }
    cout << ans;
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