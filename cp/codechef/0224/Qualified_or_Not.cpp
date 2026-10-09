#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int z = max(x, y);
    if (n >= 2 * z) cout << "YES" << endl;
    else cout << "NO" << endl;
}