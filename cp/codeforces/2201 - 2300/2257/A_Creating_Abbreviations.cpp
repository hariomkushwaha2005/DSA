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
    ll n, m;
    cin >> n >> m;

    vector<int> v(26, 0);

    for (int i = 0; i < n; ++i)
    {
        string t;
        cin >> t;
        v[t[0] - 'a'] = 1;
    }

    bool is = false;
    for (int i = 0; i < m; ++i)
    {
        string t;
        cin >> t;
        for (char c : t)
        {

            if (!v[c - 'A'])
            {
                is = true;
            }
        }
    }
    if(is){
        cout << "NO" << endl;
        return;
    }
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