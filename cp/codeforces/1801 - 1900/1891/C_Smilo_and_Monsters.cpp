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

void solve()
{
    ll n;
    cin >> n;

    vll v(n);
    for (auto &i : v)
        cin >> i;

    ranges::sort(v);

    ll i = 0, j = n - 1;
    ll sum = 0;
    ll ops = 0;
    while (i < j)
    {
        if (sum + v[i] <= v[j])
        {
            sum += v[i];
            ops += v[i];
            ++i;
            if (sum == v[j])
            {
                ops++;
                sum = 0;
                --j;
            }
        }
        else
        {
            ll need = v[j] - sum;
            ops += (need + 1);
            v[i] -= need;
            sum = 0;
            --j;
        }
    }

    if (i == j)
    {
        ll need = (v[i] - sum) / 2;
        ops += need;
        sum += need;
        v[i] -= need;
        if (sum > 0)
        {
            v[i] -= sum;
            ops++;
        }
        if (v[i] > 0)
            ops++;
    }

    cout << ops << endl;
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