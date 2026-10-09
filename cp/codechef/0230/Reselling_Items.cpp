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
    ll n,k;
    cin>>n>>k;
    vll v(n);
    in(v);

    sort(all(v));
    int ans = 0;
    for(int i = n-1; i >= 0;i--){
        if(v[i]>5){
            if(k>0){
                ans+=v[i]-5;
                k--;
            }
            else if(v[i]>10) ans+=v[i]-10;
        }
        else break;
    }
    cout<<ans<<endl;
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