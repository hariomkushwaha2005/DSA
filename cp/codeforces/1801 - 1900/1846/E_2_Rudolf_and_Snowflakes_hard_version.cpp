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

void solve()
{
    ll n;
    cin >> n;

    for (int i = 3; i <= 60; ++i)
    {
        int low = 2, high = 1000000000;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            ll cs = 1, term = 1;
            bool of = 0;
            for (int j = 1; j < i; ++j)
            {
                if(term > LLONG_MAX/mid){
                    of = 1;
                    break;
                }
                term *= mid;
                if(cs > LLONG_MAX - term){
                    of = 1;
                    break;
                }
                cs += term;
                if (cs > n)
                {
                    of = 1;
                    break;
                }
            }
            if (cs == n)
            {
                cout << "YES" << endl;
                return;
            }
            else if (cs > n || of)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
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