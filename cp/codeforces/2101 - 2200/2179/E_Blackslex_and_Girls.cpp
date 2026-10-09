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
    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    vi v(n);
    for(auto &it : v) cin >> it;

    ll xmin = 0, xmax = 0, ymin = 0, ymax = 0;
    bool zero = false, one = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            one = true;
            ymin += v[i]/2 + 1;
            xmax += v[i]/2;
        }
        else{
            zero = true;
            xmin += v[i]/2 + 1;
            ymax += v[i]/2;
        }
    }

    if(x < xmin || y < ymin)
        cout << "NO" << endl;
    
    else if(!zero && (xmax + y - ymin < x))
        cout << "NO" << endl;
    
    else if(!one && (ymax + x - xmin < y))
        cout << "NO" << endl;
    
    else cout << "YES" << endl;
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