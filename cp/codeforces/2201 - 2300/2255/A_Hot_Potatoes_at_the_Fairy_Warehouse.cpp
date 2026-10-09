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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll b = 0, r = 0;
    n <<= 1;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            if (s[(i + 1) % n] == '1')
            {
                if (i & 1)
                    b++;
                else
                    r++;
            }
            else
            {
                if (i & 1)
                    r++;
                else
                    b++;
            }
        }
    }

    cout << b <<" "<< r << endl;
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