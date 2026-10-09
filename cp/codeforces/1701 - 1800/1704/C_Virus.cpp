#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    // Your logic goes here
    int n, m;
    cin >> n >> m;

    vi v(m);
    for (auto &x : v)
    {
        cin >> x;
    }

    sort(all(v));

    int last = v[0];

    vi dist;
    for (int i = 1; i < m; i++)
    {
        dist.push_back(v[i] - last - 1);
        last = v[i];
    }
    dist.push_back(n + v[0] - v[m - 1] - 1);

    sort(dist.rbegin(), dist.rend());

    int save = 0, sub = 0;
    for(auto &it : dist){
        if(it - sub <= 1){
            if(it - sub == 1){
                save++;
            }
            break;
        } 
        save += (it - 1 - sub);
        sub += 4;
    }
    cout << n - save << endl;
}

int main()
{
    fast_io();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}