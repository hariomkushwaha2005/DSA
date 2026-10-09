#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size() 

inline void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    // Your logic goes here
    int n;
    cin >> n;

    vector<pair<int,int>> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = {x,i};
    }
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b[i] = {x,i};
    }
    sort(b.rbegin(), b.rend());
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        c[i] = {x,i};
    }
    sort(c.rbegin(), c.rend());

    int ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(b[j].second == a[i].second) continue;
            for(int k = 0; k < 3; k++){
                if(c[k].second == b[j].second || c[k].second == a[i].second) continue;
                ans = max(ans, a[i].first + b[j].first + c[k].first);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    fast_io();
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}