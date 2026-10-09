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
    ll n;
    cin >>n;
    string s;
    cin >>s;

    string t = s;
    sort(all(t));
    vector<int> ans;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) ans.push_back(i + 1);
    }
    if(!ans.empty()){
        cout << "Alice" << endl;
        cout << ans.size() << endl;
        for(auto &it : ans) cout << it << " ";
        cout << endl;
        return;
    }
    cout << "Bob" << endl;
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