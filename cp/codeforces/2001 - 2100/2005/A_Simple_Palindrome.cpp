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
    int n;
    cin >> n;

    int x = (n + 4) / 5;
    for (int i = 0; i < x; ++i)
        cout << 'a';
    x = (n + 3) / 5;
    for (int i = 0; i < x; ++i)
        cout << 'e';
    x = (n + 2) / 5;
    for (int i = 0; i < x; ++i)
        cout << 'i';
    x = (n + 1) / 5;
    for (int i = 0; i < x; ++i)
        cout << 'o';
    x = n / 5;
    for (int i = 0; i < x; ++i)
        cout << 'u';
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