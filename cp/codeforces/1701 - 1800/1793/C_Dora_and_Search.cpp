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
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        int minn = v[i], mini = i, maxx = v[i], maxi = i;
        for(int j = i; j < n; j++){
            if(v[j] < minn){
                mini = j;
                minn = v[j];
            }
            if(v[j] > maxx) {
                maxi = j;
                maxx = v[j];
            }
            if(mini != i && mini != j && maxi != j && maxi != i){
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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