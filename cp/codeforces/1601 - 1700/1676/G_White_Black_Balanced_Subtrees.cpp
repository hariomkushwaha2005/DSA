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

struct node
{
    int sub;
    int w;
    int b;
    node(int sub, int w, int b) : sub(sub), w(w), b(b) {}
};

node help(int cur, const string &s, const vector<vi> &adj)
{
    int w = 0, b = 0, sub = 0;

    if (s[cur] == 'W')
        w++;
    else
        b++;

    for (auto it : adj[cur])
    {
        auto child = help(it, s, adj);
        w += child.w;
        b += child.b;
        sub += child.sub;
    }

    if (b == w)
        sub++;
    return {sub, w, b};
}

void solve()
{
    int n;
    cin >> n;

    vector<vi> adj(n);
    for (int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        adj[x - 1].push_back(i);
    }

    string s;
    cin >> s;

    cout <<  help(0, s, adj).sub << endl;
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