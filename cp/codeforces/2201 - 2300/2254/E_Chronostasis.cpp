#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

void solve()
{
    ll n;
    cin >> n;

    vll ms1;
    multiset<ll> ms2;

    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        if (x > 0)
            ms1.push_back(x);
        else
            ms2.insert(-x);
    }
    sort(all(ms1));

    vll a(n);
    int i = 0, l = 0;
    if (ms1.empty())
    {
        cout << -1 << endl;
        return;
    }
    a[i++] = ms1[l++];
    while (i < n)
    {
        auto it = ms2.lower_bound(a[i - 1]);
        if (it != ms2.begin())
        {
            --it;
            a[i] = a[i - 1] - *it;
            ms2.erase(it);
        }
        else
        {
            if (l < ms1.size())
            {
                a[i] = a[i - 1] + ms1[l];
                ++l;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        ++i;
    }
    for (auto it : a)
        cout << it << " ";
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