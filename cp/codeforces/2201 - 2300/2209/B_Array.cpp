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
    ll n;
    cin >> n;
    vll v(n);
    in(v);

    vector<pair<int,int>> ans(n, {0,0});
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(v[i]>v[j]) ans[i].first++;
            if(v[i]<v[j]) ans[i].second++;
        }
    }
    for(int i = 0; i < n; i++){
        cout<< max(ans[i].first,ans[i].second)<<" ";
    }
    cout<<endl;
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