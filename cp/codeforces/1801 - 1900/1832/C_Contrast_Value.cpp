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

    vi v(n);
    for(auto &x : v) cin >> x;

    int ans = n;
    for(int i = 0; i < n; i++){
        int prev = -1;
        if(i > 0) prev = v[i - 1];
        while(i < n - 1 && v[i] == v[i + 1]){
            i++;
            ans--;
        }
        int next = -1;
        if(i < n - 1) next = v[i + 1];
        if(prev != -1 && next != -1 && prev < v[i] && next > v[i]) ans--;
        if(prev != -1 && next != -1 && prev > v[i] && next < v[i]) ans--;
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