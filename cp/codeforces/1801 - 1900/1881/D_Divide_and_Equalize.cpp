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

int arr[1000001];

void solve()
{
    ll n;
    cin >> n;

    vector<int> used;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        int j = 2;
        while (j * j <= x)
        {
            if (x % j == 0)
            {
                if (arr[j] == 0)
                    used.push_back(j);
                while (x % j == 0)
                {
                    arr[j]++;
                    x /= j;
                }
            }
            ++j;
        }
        if (x > 1)
        {
            if (arr[x] == 0)
                used.push_back(x);
            arr[x]++;
        }
    }

    bool what = 0;
    for (int j : used)
    {
        if (arr[j] % n != 0)
        {
            what = 1;
        }
        arr[j] = 0;
    }
    if (what)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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