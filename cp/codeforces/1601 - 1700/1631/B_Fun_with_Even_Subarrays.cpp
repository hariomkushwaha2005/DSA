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
    int n;
    cin >> n;

    vll v(n);
    in(v);

    int p = n-2;
    int ops = 0;
    while(p >= 0){
        if(v[p] == v[n-1]) p--;
        else {
            ops++;
            p = 2 * p - n +1 ;
        }
    }
    cout << ops << endl;
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