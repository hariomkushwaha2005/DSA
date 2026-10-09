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

void solve()
{
    ll n;
    cin >> n;

    ll a = 2;
    vll v;
    while (a * a < n)
    {
        if (n % a == 0)
        {
            n /= a;
            v.push_back(a);
            if (v.size() == 2)
                break;
        }
        a++;
    }
    if (v.size() == 2 && n > v.back())
    {
        cout << "YES" << endl;
        cout << v.front() << " " << v.back() << " " << n << endl;
        return;
    }
    cout << "NO" << endl;
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