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
    ll x, y, k;
    cin >> x >> y >> k;

    ll mul = y / x;
    ll rem = y % x;
    ll val = 0;
    while (k > 0 && mul > 1)
    {
        ll next = min(rem / (mul - 1), k);

        if (next == 0)
        {
            val += rem;
            k--;
            y++;
            x++;
            rem = y % x;
            mul = y / x;
            continue;
        }
        
        ll lt = rem - (next - 1) * (mul - 1);
        val += next * (lt + rem) / 2;
        k -= next;
        y += next;
        x += next;
        rem = y % x;
        mul = y / x;
    }
    val += k * rem;
    cout << val << endl;
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