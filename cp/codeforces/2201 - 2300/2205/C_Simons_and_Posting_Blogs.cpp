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
    ll n;
    cin >> n;

    vector<vi> v(n);
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            int x;
            cin >> x;
            maxx = max(maxx, x);
            v[i].push_back(x);
        }
    }
    vi vis(maxx + 1, -1);
    for (int i = 0; i < n; i++)
    {
        vi vec;
        for (int j = v[i].size() - 1; j >= 0; j--)
        {
            if (vis[v[i][j]] != i)
            {
                vis[v[i][j]] = i;
                vec.push_back(v[i][j]);
            }
        }
        swap(v[i], vec);
    }
    vi ptr(n, 0);
    auto comp = [&](int idx1, int idx2) -> bool
    {
        int &i = ptr[idx1], &j = ptr[idx2];
        while (i < v[idx1].size() && vis[v[idx1][i]] == -1)
            i++;
        while (j < v[idx2].size() && vis[v[idx2][j]] == -1)
            j++;
        int tempi = i, tempj = j;
        while (tempi < v[idx1].size() && tempj < v[idx2].size())
        {
            while (tempi < v[idx1].size() && vis[v[idx1][tempi]] == -1)
                tempi++;
            while (tempj < v[idx2].size() && vis[v[idx2][tempj]] == -1)
                tempj++;
            if (tempi < v[idx1].size() && tempj < v[idx2].size() && v[idx1][tempi] == v[idx2][tempj])
            {
                tempi++;
                tempj++;
            }
            else
                break;
        }
        if (i == v[idx1].size())
            return false;
        else if (j == v[idx2].size())
            return true;
        else if (tempi == v[idx1].size())
            return true;
        else if (tempj == v[idx2].size())
            return false;
        return v[idx1][tempi] < v[idx2][tempj];
    };
    int i = 0;
    while (i < n)
    {
        int mini = 0;
        for (int j = 1; j < n; j++)
        {
            if (comp(j, mini))
                mini = j;
        }
        for (auto &z : v[mini])
        {
            if (vis[z] != -1)
            {
                cout << z << " ";
                vis[z] = -1;
            }
        }
        i++;
    }
    cout << endl;
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