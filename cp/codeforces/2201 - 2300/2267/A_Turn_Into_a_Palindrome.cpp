#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

inline void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    ll n;
    cin >> n;

    char c;
    cin >> c;

    string s;
    cin >> s;

    int i = 0, j = n - 1;
    ll cnt = 0;
    while (i < j)
    {
        if (s[i] == s[j]){
            bool c;
        }
        else if (s[i] == c || s[j] == c)
            cnt++;
        else
            cnt += 2;

        ++i;
        --j;
    }
    cout << cnt << endl;
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