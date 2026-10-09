#pragma GCC optimize("O3,unroll-loops")

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

struct bea
{
    ll a;
    ll b;
    ll c;
    ll d;

    bool operator<(const bea &other) const
    {
        return a > other.a;
    }
};

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<vll> a(n);
    vector<vll> b(n);

    for (int i = 0; i < n; ++i)
    {
        ll m;
        cin >> m;

        ll y;
        for (int j = 0; j < m; ++j)
        {
            cin >> y;
            a[i].push_back(y);
        }
        for (int j = 0; j < m; ++j)
        {
            cin >> y;
            b[i].push_back(y);
        }
    }

    vll idx(n, 0);
    priority_queue<bea> pq;
    for (int i = 0; i < n; ++i)
    {
        ll sum = 0;
        ll thres = 0;
        ll curr = idx[i];
        while (sum <= 0 && curr < a[i].size())
        {
            thres = max(thres, a[i][curr] - sum);
            sum += b[i][curr] - a[i][curr];
            curr++;
        }
        if (sum > 0)
            pq.push({thres, sum, i, curr});
    }

    while (!pq.empty())
    {
        bea c = pq.top();
        pq.pop();
        if (c.a > x)
            break;
        x += c.b;

        idx[c.c] = c.d;

        ll sum = 0;
        ll thres = 0;
        ll curr = idx[c.c];
        while (sum <= 0 && curr < a[c.c].size())
        {
            thres = max(thres, a[c.c][curr] - sum);
            sum += b[c.c][curr] - a[c.c][curr];
            curr++;
        }
        if (sum > 0)
            pq.push({thres, sum, c.c, curr});
    }

    ll ans = 0, bns = 0;
    for (int i = 0; i < n; ++i)
    {
        ll y = x;
        ll curr = idx[i];
        while (curr < a[i].size() && a[i][curr] <= y)
        {
            y += b[i][curr] - a[i][curr];
            curr++;
        }
        if (curr > ans)
        {
            ans = curr;
            bns = i;
        }
    }

    cout << ans << " " << bns + 1 << endl;
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