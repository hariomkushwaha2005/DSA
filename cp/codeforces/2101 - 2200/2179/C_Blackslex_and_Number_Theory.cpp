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
    int minn = 1e9;
    for(auto &x : v){
        cin >> x;
        minn = min(minn, x);
    }
    
    int k = 1e9;
    for(int i = 0; i < n; i++){
        if(v[i] != minn) k = min(k, v[i] - minn);
    }

    cout << max(minn, k) << endl;

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