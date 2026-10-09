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

    vll v(n);
    for(auto &x : v) cin >> x;

    ll eg = v[0], og = v[1];
    for (int i = 0; i < n; i++){
        if(i&1) 
            og = __gcd(og, v[i]);
        else
            eg = __gcd(eg, v[i]);
    }
    ll ol = 1, el = 1;
    for(int i = 0; i < n; i++){
        if(i&1) ol = max(ol, __gcd(eg, v[i]));
        else el = max(el, __gcd(og, v[i]));
    }
    if(ol < eg && el < og) cout << max(eg, og) << endl;
    else if (ol < eg) cout << eg << endl;
    else if(el < og) cout << og <<endl;
    else cout << 0 << endl;
     
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