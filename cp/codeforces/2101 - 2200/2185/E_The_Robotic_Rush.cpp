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
    int n, m, k;
    cin >> n >> m >> k;

    vi a(n);
    for(auto &x : a) cin >> x;
    sort(all(a));
    
    vi b(m);
    for(auto &x : b) cin >> x;
    sort(all(b));
    
    string s;
    cin >> s;

    vector<vi> mp(2*k + 1);

    int i = n - 1, j = m - 1;
    while(i >= 0){
        while(j >= 0 && a[i] < b[j]) j--;
        if(j >= 0 && b[j] - a[i] >= -k) mp[b[j] - a[i] + k].push_back(a[i]);
        i--;
    }
    i = 0, j = 0;
    while(i < n){
        while(j < m && a[i] > b[j]) j++;
        if(j < m && b[j] - a[i] <= k) mp[b[j] - a[i] + k].push_back(a[i]);
        i++;
    }

    int cnt = 0;
    int robo = n;
    unordered_set<int> st;
    for(int i = 0; i < k; i++){
        if(s[i] == 'L') cnt--;
        else cnt++;

        for(auto &x : mp[cnt + k]){
            if(!st.count(x)){
                st.insert(x);
                robo--;
            }
        }
        mp[cnt + k].clear();
        cout<< robo <<" ";
    }
    cout << '\n';
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