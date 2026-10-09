#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

struct Node
{
    ll minn;
    ll maxx;
    Node(ll minn, ll maxx)
    {
        this->minn = minn;
        this->maxx = maxx;
    }
};

bool func(ll node, vector<vll> &a, vector<Node> &b)
{
    if (a[node].size() == 0)
        return true;
    sort(all(a[node]));

    for (auto x : a[node])
        if (!func(x, a, b))
            return false;

    ll minn = b[a[node][0]].minn, maxx = b[a[node][0]].maxx;
    ll cnt = 0;
    for (int i = 1; i < a[node].size(); ++i)
    {
        if (b[a[node][i - 1]].maxx > b[a[node][i]].minn)
            cnt++;
        minn = min(minn, b[a[node][i]].minn);
        maxx = max(maxx, b[a[node][i]].maxx);
    }
    if (b[a[node][a[node].size() - 1]].maxx > b[a[node][0]].minn)
        cnt++;
    if (cnt > 1)
        return false;
    b[node].minn = minn;
    b[node].maxx = maxx;
    return true;
}

void solve()
{
    ll n;
    cin >> n;

    vector<vll> a(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        ll x;
        cin >> x;
        a[x].push_back(i);
    }

    vector<Node> b(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        b[i].minn = x;
        b[i].maxx = x;
    }

    if (func(1, a, b))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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