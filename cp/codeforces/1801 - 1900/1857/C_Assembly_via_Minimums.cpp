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

    int size = n*(n - 1)/2;

    vi v(size);
    map<int,int> mp;
    for(auto &x : v){
        cin >> x;
        mp[x]++;
    }

    int less = 0;

    for(auto &x : mp){
        while(x.second > 0){
            cout << x.first << " ";
            x.second -= (n - 1 - less);
            less++;
        }
    }
    cout << (int)1e9 <<endl;
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