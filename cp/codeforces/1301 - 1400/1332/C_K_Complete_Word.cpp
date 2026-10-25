#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll ops = 0;
    for (int i = 0; i <= k / 2; ++i)
    {
        if (i == k / 2 && !(k & 1))
            break;

        vll f(26, 0);
        ll maxf = 0;
        for (int j = 0; j + i < n; j += k)
        {
            f[s[j + i] - 'a']++;
            maxf = max(maxf, f[s[i + j] - 'a']);

            if (i != k / 2)
            {
                f[s[j + k - 1 - i] - 'a']++;
                maxf = max(maxf, f[s[k - 1 - i + j] - 'a']);
            }
        }
        ll b = (n / k);
        if (i != k / 2)
            b <<= 1;
        ops += b - maxf;
    }

    cout << ops << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}