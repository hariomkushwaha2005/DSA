#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

typedef long long ll;
typedef vector<long long> vll;

#define in(v) for (auto& _x : v) cin >> _x;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, k; 
    cin >> n >> k;

    vll v(n);
    in(v);

    sort(all(v));

    int l = 0, r = 0;
    while(r < n){
        if(v[r] - v[l] == k){
            cout << "YES" << endl;
            return;
        }
        else if(v[r] - v[l] < k)
            r++;
        
        else l++;
    }
    cout << "NO" << endl;
}

int main() {
    fast_io();

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}