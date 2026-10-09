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

    vll st(n + 1);
    st[0] = 0;
    ll c = 0;
    bool ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        if (i & 1)
            c += x;
        else
            c -= x;
        st[i + 1] = c;
    }
    sort(st.begin(), st.end());
    for (int i = 1; i <= n; ++i)
        if (st[i] == st[i - 1])
        {
            ans = 1;
            break;
        }
    if (ans)
        cout << "YES" << endl;
    else
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