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
    ll n, k;
    cin>>n>>k;
    vll v(n);
    in(v);

    for(int i=0;i<n;){
        int a = 0;
        while(a<=k){
            if(v[i+a]==1) break;
            a++;
        }
        if(a>k){
            cout<<"No"<<endl;
            return;
        }
        i+=a;
        int b = 0;
        while(b < k){
            if(v[i+b]==1) {
                cout<<"No"<<endl;
                return;
            }
            b++;
        }
        i+=b;
    }
    cout<<"Yes"<<endl;
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