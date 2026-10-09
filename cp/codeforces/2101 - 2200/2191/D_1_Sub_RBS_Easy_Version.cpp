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

    string s;
    cin >> s;

    int l = n - 1;
    while (s[l] != '(')
        --l;

    for (int i = 0; i < l - 1; ++i)
    {
        if (s[i] == ')' && s[i + 1] == '('){
            cout << n - 2 << endl;
            return;
        }
    }
    cout << -1 << endl;
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