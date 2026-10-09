#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

typedef long long ll;
typedef vector<long long> vll;

#define all(x) (x).begin(), (x).end()

void solve() {
    ll x, y, z;
    cin>>x>>y>>z;
    int a = 0;
    if(x>=50) a++;
    if(y>=50) a++;
    if(z>=50) a++;
    if(a>=2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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