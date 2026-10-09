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
    
    cout << (1 << n) - 1 << " "; 
    
    int c = n - 1;

    while(c >= 0){
        int rembit = n - c - 1;

        for(int i = 0; i < (1 << rembit); i++){
            cout << ((i << (c + 1)) | ((1 << c) - 1)) << " ";
        }
        
        c--;
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