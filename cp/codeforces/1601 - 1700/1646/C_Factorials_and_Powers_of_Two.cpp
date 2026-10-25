#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

vll fact;
vector<pair<ll, ll>> emo;
void facto()
{
    ll i = 1;
    ll j = 1;
    while (i <= 1e12)
    {
        fact.push_back(i);
        j++;
        i *= j;
    }

    ll sz = fact.size();
    for (ll mask = 0; mask < (1LL << sz); mask++)
    {
        ll val = 0;
        ll count = 0;
        for (ll bit = 0; bit < sz; bit++)
        {
            if ((mask >> bit) & 1)
            {
                val += fact[bit];
                count++;
            }
        }
        emo.push_back({val, count});
    }
}

void solve()
{
    ll n;
    cin >> n;

    ll ans = LLONG_MAX;
    ll i = 0;
    while (i < emo.size() && emo[i].first <= n)
    {
        ans = min(ans, emo[i].second + __builtin_popcountll(n - emo[i].first));
        ++i;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    facto();
    ranges::sort(emo);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}