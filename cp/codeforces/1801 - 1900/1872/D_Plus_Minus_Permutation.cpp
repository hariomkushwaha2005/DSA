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

ll lcm(ll a, ll b){
    return a*b/__gcd(a,b);
}

void solve() {
    // Your logic goes here
    int n, x, y;
    cin >> n >> x >> y;

    int a = (n/x) - (n/lcm(x,y));
    int b = (n/y) - (n/lcm(x,y));
    
    ll sumb = b*(b+1)/2;
    ll suma = n*(n+1)/2 - (n-a)*(n-a+1)/2;

    cout << suma - sumb << endl;
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