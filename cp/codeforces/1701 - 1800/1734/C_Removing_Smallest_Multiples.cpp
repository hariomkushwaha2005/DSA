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
    int n;
    cin >> n;

    string s;
    cin >> s;

    string used(n, '0');
    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            for(int j = i; j < n; j+=(i+1)){
                if(s[j] == '1') break;
                else{
                    if(used[j] == '0'){
                        used[j] = '1';
                        ans = ans + i + 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;
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