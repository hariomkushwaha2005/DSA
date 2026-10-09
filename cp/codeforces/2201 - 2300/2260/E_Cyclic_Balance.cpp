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
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vll zz(n), oo(n), oz(n);
    zz[0] = 0;
    oo[0] = 0;
    oz[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        zz[i] = zz[i - 1];
        oo[i] = oo[i - 1];
        oz[i] = oz[i - 1];
        if (s[i] == '1')
        {
            if (s[i - 1] == '1')
                oo[i]++;
        }
        else
        {
            if (s[i - 1] == '1')
                oz[i]++;
            else
                zz[i]++;
        }
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        --l, --r;
        ll curoz = oz[r] - oz[l];
        ll curoo = oo[r] - oo[l];
        ll curzz = zz[r] - zz[l];
        if (s[l] == '1')
        {
            if (s[r] == '1')
                curoo++;
        }
        else
        {
            if (s[r] == '1')
                curoz++;
            else
                curzz++;
        }

        if (curzz > curoo)
            swap(curzz, curoo);

        if (curoz >= curoo)
            cout << (curoz - curoo + curoz - curzz) << endl;
        else if (curoz >= curzz)
        {
            ll c = ((curoo - curoz) >> 1);
            curoz += c;
            curoo -= c;
            c += (curoo - curzz);
            if (curoo > curoz)
                c += 2;

            cout << c << endl;
        }
        else
        {
            ll c = curoo - curzz;
            c = min(c, ((curoo - curoz) >> 1));
            curoz += c;
            curoo -= c;
            if (curoo > curzz)
            {
                c += (curoo - curzz);
                if (curoo > curoz)
                    c += 2;
            }
            else
            {
                ll f = curoo - curoz;
                c += (f / 3) * 2;
                if (f % 3 == 1)
                    c += 2;
                else if (f % 3 == 2)
                    c += 4;
            }
            cout << c << endl;
        }
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