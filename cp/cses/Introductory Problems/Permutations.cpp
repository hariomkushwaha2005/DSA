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

    if (n == 2 || n == 3){
        cout << "NO SOLUTION" << endl;
        return;
    }
    
    for(int i = 2; i <= n; i += 2) cout << i << " ";
    for(int i = 1; i <= n; i += 2) cout << i << " ";
    cout << endl;
}

int main()
{
    fast_io();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}