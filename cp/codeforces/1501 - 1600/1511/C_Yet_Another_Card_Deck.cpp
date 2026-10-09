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

    vi pos(51, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(pos[x] == 0){
            pos[x] = i+1;
        }
    }

    for(int i = 0; i < q; i++){
        int x;
        cin >> x;

        cout << pos[x] << " ";

        for(int j = 0; j <= 50; j++){
            if(pos[j] != 0 && pos[j] < pos[x]){
                pos[j]++;
            }
        }
        pos[x] = 1;
    }
    cout << endl;
}

int main() {
    fast_io();
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}