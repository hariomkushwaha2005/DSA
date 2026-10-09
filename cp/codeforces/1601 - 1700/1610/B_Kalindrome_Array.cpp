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
    for(auto& x : v) cin >> x;

    int i = 0, j = n - 1;
    int del = -1;
    bool del1 = true;
    while(i < j){
        if(v[i] != v[j]) {
            if(del == -1){
                del = v[i];
                i++;
            }
            else if (v[i] == del){
                i++;
            }
            else if(v[j] == del){
                j--;
            }
            else{
                del1 = false;
                break;
            }
        }
        else{
            i++;
            j--;
        }
    }
    if(del1){
        cout << "YES" << endl;
        return;
    }
    del1 = true;
    i = 0, j = n - 1, del = -1;
    while(i < j){
        if(v[i] != v[j]) {
            if(del == -1){
                del = v[j];
                j--;
            }
            else if (v[i] == del){
                i++;
            }
            else if(v[j] == del){
                j--;
            }
            else{
                del1 = false;
                break;
            }
        }
        else{
            i++;
            j--;
        }
    }
    if(del1){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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