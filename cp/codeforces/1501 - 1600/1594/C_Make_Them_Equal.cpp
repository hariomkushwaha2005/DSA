#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt+=s[i]==c;
    }
    if(cnt == n){
        cout << 0 << endl;
        return;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        int j = i;
        bool match = 1;
        while (j < n)
        {
            match &= s[j] == c;
            j += (i + 1);
            if (!match)
                break;
        }
        if (match)
        {
            cout << 1 << endl;
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n << " " << n - 1 << endl;
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