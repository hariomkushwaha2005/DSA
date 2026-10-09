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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    ll n;
    cin >> n;

    vll a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    vll pre(n + 1);
    pre[0] = 0;
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + b[i];

    vll end(n + 1, 0), tot(n + 1, 0);
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        ll l = i, h = n;
        while (l <= h)
        {
            ll mid = l + (h - l) / 2;
            if (a[i] >= pre[mid] - pre[i])
                l = mid + 1;
            else
                h = mid - 1;
        }
        tot[h] += a[i] - (pre[h] - pre[i]);
        end[h]++;
        cnt++;
        cnt -= end[i];
        tot[i] += b[i] * cnt;
    }
    for (int i = 0; i < n; ++i)
        cout << tot[i] << " ";
    cout << endl;
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