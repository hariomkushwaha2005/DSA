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
void printy(int mini, int x, int y, vector<int> &v){
    for(int i = mini; i < y; i++){
        cout << v[i] << " ";
    }
    for(int i = x; i < mini; i++){
        cout << v[i] << " ";
    }
}

void solve() {
    // Your logic goes here
    int n, x, y;
    cin >> n >> x >> y;

    vi v(n);
    for(auto &x : v) cin >> x;

    int mini = x;
    for(int i = x; i < y; i++){
        if(v[i] < v[mini]){
            mini = i;
        }
    }

    bool print = false;
    for(int i = 0; i < x; i++){
        if(v[i] > v[mini] && !print){
            printy(mini, x, y, v);
            print = true;
        }
        cout << v[i] << " ";
    }
    for(int i = y; i < n; i++){
        if(v[i] > v[mini] && !print){
            printy(mini, x, y, v);
            print = true;
        }
        cout << v[i] << " ";
    }
    if(!print){
            printy(mini, x, y, v);
            print = true;
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