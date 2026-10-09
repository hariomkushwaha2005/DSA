#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    // Your logic goes here
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            v[j] |= (1 << (c - 'a'));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;
        string ans = "";
        bool match = true;
        for (int j = 0; j < i; j++)
        {
            int val = v[j];
            for (int l = j; l < n; l += i)
            {
                val &= v[l];
            }
            if (val > 0)
            {
                ans += 'a' + __builtin_ctz(val);
            }
            else
            {
                match = false;
                break;
            }
        }
        if(match){
            int z = n / i;
            for(int m = 0; m < z; m++){
                cout << ans;
            }
            cout << endl;
            return;
        }
    }
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