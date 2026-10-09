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
    int n, q;
    cin >> n >> q;
    
    vector<pair<int,ll>> mp;
    ll step = 0, height = 0;

    vll v(n);
    for(auto &x : v){
        cin >> x;
        height += x;
        if(x > step){
            step = x;
            mp.push_back({x,height});
        }
        else{
            mp.back().second = height;
        }
    }

    vi query(q);
    for(auto &x : query) cin >> x;

    for(auto &x : query){
        int low = 0, high = mp.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mp[mid].first > x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(high == -1) cout << 0 << " ";
        else cout << mp[high].second << " ";
    }
    cout << endl;

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