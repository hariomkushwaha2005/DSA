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

void first() {
    // Your logic goes here
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n + 1,1e9);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &it : adj[node]){
            if(dist[it] > dist[node] + 1){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    string s;
    for(int i = 1; i <= n; i++){
        int it = dist[i];
        if(it%3 == 0) s+='b';
        else if(it%3 == 1) s+='r';
        else s+='g';
    }

    cout << s << endl;
}
void second() {
    // Your logic goes here
    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int b = -1, g = -1, r = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b') b = i;
            else if (s[i] == 'g') g = i;
            else r = i;
        }
        if(r != -1 && b != -1) cout << r + 1 << endl;
        else if(b != -1 && g != -1) cout << b + 1 << endl;
        else if (g != -1 && r != -1) cout << g + 1 << endl;
        else {
            if (r != -1) cout << r + 1 << endl;
            else if (g != -1) cout << g + 1 << endl;
            else cout << b + 1 << endl;
        }
        
    }
}

int main() {
    fast_io();
    
    string s;
    cin >> s;

    if(s == "first"){
        int t;
        cin >> t;

        while(t--) first();
    }
    else {
        int t;
        cin >> t;

        while(t--) second();
    }
    return 0;
}