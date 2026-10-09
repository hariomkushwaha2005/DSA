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
    ll a, b, c, m;
    cin >> a >> b >> c >> m;

    ll ab = (a/__gcd(a,b))*b;
    ll ac = (a/__gcd(a,c))*c;
    ll bc = (b/__gcd(b,c))*c;
    ll abc = (ab/__gcd(ab,c))*c;

    ll wa = 6*(m/a) - 3*(m/ab + m/ac) + 2*(m/abc);
    ll wb = 6*(m/b) - 3*(m/ab + m/bc) + 2*(m/abc);
    ll wc = 6*(m/c) - 3*(m/bc + m/ac) + 2*(m/abc);

    cout << wa << " " << wb << " " << wc << " " << endl;
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