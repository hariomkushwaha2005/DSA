#pragma GCC optimize("O3,unroll-loops")

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

bool check(int i, int j, vector<string> &board)
{
    for (int k = i; k >= 0; --k)
        if (board[k][j] == 'q')
            return false;

    ll k = i, l = j;
    while (k >= 0 && l >= 0)
    {
        if (board[k][l] == 'q')
            return false;
        --k;
        --l;
    }
    k = i, l = j;
    while (k >= 0 && l < 8)
    {
        if (board[k][l] == 'q')
            return false;
        --k;
        ++l;
    }
    return true;
}

int place(int i, vector<string> &board)
{
    if (i == 8)
        return 1;
    ll res = 0;
    for (int j = 0; j < 8; ++j)
    {
        if (board[i][j] == '*')
            continue;
        if (check(i, j, board))
        {
            board[i][j] = 'q';
            res += place(i + 1, board);
            board[i][j] = '.';
        }
    }
    return res;
}

void solve()
{
    vector<string> board(8);
    for (int i = 0; i < 8; ++i)
        cin >> board[i];

    cout << place(0, board) << endl;
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