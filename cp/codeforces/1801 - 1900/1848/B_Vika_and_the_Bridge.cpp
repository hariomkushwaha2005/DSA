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
    int n, k;
    cin >> n >> k;

    vi v(n);
    for(auto &x : v) cin >> x;

    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        if(mp.count(v[i])){
            if(mp[v[i]][1] <= i - mp[v[i]][0] - 1) {
                mp[v[i]][2] = mp[v[i]][1];
                mp[v[i]][1] = i - mp[v[i]][0] - 1;
            }
            else{
                mp[v[i]][2] = max(mp[v[i]][2], i - mp[v[i]][0] - 1);
            }
            mp[v[i]][0] = i;
        }
        else{
            mp[v[i]] = {i, i, 0};
        }
    }

    int ans = n/3;
    for(auto &it : mp){
        if(it.second[1] <= n - it.second[0] - 1) {
            it.second[2] = it.second[1];
            it.second[1] = n - it.second[0] - 1;
        }
        else{
            it.second[2] = max(it.second[2], n - it.second[0] - 1);
        }
        ans = min(ans, max(it.second[1]/2, it.second[2]));
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