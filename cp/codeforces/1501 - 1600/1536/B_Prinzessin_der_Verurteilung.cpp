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

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<string> s1;
    set<string> s2;
    set<string> s3;

    for (int i = 0; i < n; ++i)
    {
        s1.insert(s.substr(i, 1));
        if (i < n - 1)
            s2.insert(s.substr(i, 2));
        if (i < n - 2)
            s3.insert(s.substr(i, 3));
    }

    string a = "a";
    if (s1.size() < 26)
    {
        for (auto c : s1)
        {
            if (c != a)
            {
                break;
            }
            a[0]++;
        }
    }
    else if (s2.size() < 676)
    {
        a = "aa";
        for (auto c : s2)
        {
            if (c != a)
            {
                break;
            }
            if (a[1] == 'z')
            {
                a[0]++;
                a[1] = 'a';
            }
            else
                a[1]++;
        }
    }
    else
    {
        a = "aaa";
        for (auto c : s3)
        {
            if (c != a)
            {
                break;
            }
            if (a[2] == 'z')
            {
                if (a[1] == 'z')
                {
                    a[0]++;
                    a[1] = 'a';
                    a[2] = 'a';
                }
                else
                {
                    a[1]++;
                    a[2] = 'a';
                }
            }
            else
            {
                a[2]++;
            }
        }
    }
    cout << a << endl;
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