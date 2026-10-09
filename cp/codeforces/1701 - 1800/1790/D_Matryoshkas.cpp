#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

// #define endl '\n'
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

    sort(all(v));

    int ans = 0;
    int last = 0;
    int lastoc = 0;
    for(int i = 0; i < n; i++){
        int oc = 1;
        while(i < n - 1 && v[i] == v[i + 1]){
            oc++;
            i++;
        }
        if(v[i] == last + 1){
            if(lastoc > oc) ans += (lastoc - oc);
        }
        else ans += lastoc;
        last = v[i];
        lastoc = oc;
    }
    cout << lastoc + ans << endl;
    
}

int main() {
    // fast_io();
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}