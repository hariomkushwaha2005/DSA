#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int n;
    cin >> n;

    int maxDish = 0;
    int winners = 0;
    for (int i = 0; i < n; ++i)
    {
        int curDish;
        cin >> curDish;
        if (curDish > maxDish)
        {
            winners = 1;
            maxDish = curDish;
        }
        else if (maxDish == curDish)
            winners++;
    }

    cout << winners << endl;
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