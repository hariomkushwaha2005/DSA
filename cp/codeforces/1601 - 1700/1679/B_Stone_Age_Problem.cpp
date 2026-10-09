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

ll fetch(int i, int j, int p, int l, int r, vll &seg, vector<int> &lazy)
{
    int len = r - l + 1;
    if (lazy[p] != -1)
    {
        seg[p] = 1LL * len * lazy[p];
        if (l != r)
        {
            lazy[2 * p + 1] = lazy[p];
            lazy[2 * p + 2] = lazy[p];
        }
        lazy[p] = -1;
    }
    if (i > r || j < l)
        return 0;
    else if (i > l || j < r)
    {
        int mid = l + (r - l) / 2;
        return fetch(i, j, 2 * p + 1, l, mid, seg, lazy) +
               fetch(i, j, 2 * p + 2, mid + 1, r, seg, lazy);
    }

    return seg[p];
}
void update(int i, int j, int x, int p, int l, int r, vll &seg, vector<int> &lazy)
{

    int len = r - l + 1;
    if (lazy[p] != -1)
    {
        seg[p] = 1LL * len * lazy[p];
        if (l != r)
        {
            lazy[2 * p + 1] = lazy[p];
            lazy[2 * p + 2] = lazy[p];
        }
        lazy[p] = -1;
    }

    if (i > r || j < l)
        return;
    else if (i > l || j < r)
    {
        int mid = l + (r - l) / 2;
        update(i, j, x, 2 * p + 1, l, mid, seg, lazy);
        update(i, j, x, 2 * p + 2, mid + 1, r, seg, lazy);
        seg[p] = seg[2 * p + 1] + seg[2 * p + 2];
        return;
    }

    seg[p] = 1LL * len * x;
    if (l != r)
    {
        lazy[2 * p + 1] = x;
        lazy[2 * p + 2] = x;
    }
}
void build(int p, int l, int r, vector<int> &arr, vll &seg)
{
    if (l == r)
    {
        seg[p] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * p + 1, l, mid, arr, seg);
    build(2 * p + 2, mid + 1, r, arr, seg);
    seg[p] = seg[2 * p + 1] + seg[2 * p + 2];
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vll seg(n << 2, 0);
    vi lazy(n << 2, -1);
    vi v(n);

    for (auto &x : v)
        cin >> x;

    build(0, 0, n - 1, v, seg);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x;
            cin >> i >> x;
            i--;
            update(i, i, x, 0, 0, n - 1, seg, lazy);
        }
        else
        {
            int x;
            cin >> x;
            update(0, n - 1, x, 0, 0, n - 1, seg, lazy);
        }
        cout << seg[0] << endl;
    }
}

int main()
{
    fast_io();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}