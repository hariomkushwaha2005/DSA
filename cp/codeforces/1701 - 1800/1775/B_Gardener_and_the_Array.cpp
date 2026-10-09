#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int arr[200001];

void solve()
{
    ll n;
    cin >> n;

    vector<vll> v(n);
    for (int i = 0; i < n; ++i)
    {
        ll k;
        cin >> k;
        while (k--)
        {
            ll x;
            cin >> x;
            v[i].push_back(x);
            arr[x]++;
        }
    }
    for(auto &a : v){
        bool c = true;
        for(auto b : a){
            if(arr[b] < 2){
                c = false;
                break;
            }
        }
        if(c){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 200001; ++i)
            arr[i] = 0;
        solve();
    }

    return 0;
}