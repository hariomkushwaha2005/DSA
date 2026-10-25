#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

class segmentTree
{
public:
    ll n;
    ll identityElement = 1e18;
    vll tree;
    segmentTree(const vll &arr)
    {
        n = arr.size();
        tree.resize(4 * n, identityElement);
        build(arr, 1, 0, n - 1);
    }

    ll query(ll i, ll j)
    {
        return _query(1, 0, n - 1, i, j);
    }
    void update(ll i, ll x)
    {
        _update(1, 0, n - 1, i, x);
    }

private:
    ll combine(ll a, ll b)
    {
        return min(a, b);
    }

    void build(const vll &arr, ll node, ll l, ll r)
    {
        if (l == r)
        {
            tree[node] = arr[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(arr, node << 1, l, mid);
        build(arr, node << 1 | 1, mid + 1, r);
        tree[node] = combine(tree[node << 1], tree[node << 1 | 1]);
    }
    void _update(ll node, ll l, ll r, ll i, ll x)
    {
        if (l == r)
        {
            tree[node] = x;
            return;
        }

        ll mid = (l + r) >> 1;
        if (i <= mid)
            _update(node << 1, l, mid, i, x);
        else
            _update(node << 1 | 1, mid + 1, r, i, x);

        tree[node] = combine(tree[node << 1], tree[node << 1 | 1]);
    }

    ll _query(ll node, ll l, ll r, ll i, ll j)
    {
        if (r < i || j < l)
            return identityElement;
        else if (l >= i && r <= j)
            return tree[node];
        else
        {
            ll mid = (l + r) >> 1;
            return combine(_query(node << 1, l, mid, i, j), _query(node << 1 | 1, mid + 1, r, i, j));
        }
    }
};

int main()
{
    return 0;
}