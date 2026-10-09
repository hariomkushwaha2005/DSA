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
    int n;
    cin >> n;

    vll v(n);
    for(auto &x : v){
        cin >> x;
    }
    for(int k = 2; k < 2e18; k*=2){
        int rem = v[0]%k;
        bool flag = false;
        for(auto x : v){
            if(x%k != rem){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << k << endl;
            return;
        }
    }
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