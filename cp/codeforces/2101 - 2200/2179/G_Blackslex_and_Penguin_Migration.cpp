#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

// #define endl '\n'
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

    int maxx = 0, maxi = 1;
    for(int i = 2; i <= n*n; i++){
        cout << '?' << " " << 1 << " " << i << endl;
        int dist;
        cin >> dist;
        if(dist > maxx){
            maxx = dist;
            maxi = i;
        }
    }

    vector<int> v(n*n + 1, 0);
    vector<int> dia;
    v[1] = maxx;
    for(int i = 2; i <= n*n; i++){
        if(i == maxi) continue;
        cout << '?' << " " << maxi << " " << i << endl;
        int dist;
        cin >> dist;
        v[i] = dist;
        if(dist == n - 1){
            dia.push_back(i);
        }
    }

    int sc = 0;
    maxx = 0;
    for(auto &it : dia){
        if(it == dia[0]) continue;
        cout << '?' << " " << dia[0] << " " << it << endl;
        int dist;
        cin >> dist;
        if(dist > maxx){
            maxx = dist;
            sc = it;
        }
    }

    vector<vector<int>> ans(n, vector<int> (n));
    for(int i = 1; i <= n*n; i++){
        cout << '?' << " " << sc << " " << i << endl;
        int dist;
        cin >> dist;

        int x = (v[i] - dist + n - 1)/2;
        int y = (v[i] + dist - n + 1)/2;

        ans[x][y] = i;
    }

    cout << '!' << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;
}

int main() {
    // fast_io();
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}