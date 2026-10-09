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

    int zero = 0, one = 0, two = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 1) one++;
        else if (v[i] == 2) two++;
        else zero++;
    }

    int ops = 0;
    ops += min(one, two);
    one -= ops;
    two -= ops;
    
    ops += max(one, two) / 3;

    cout << ops + zero << endl;
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