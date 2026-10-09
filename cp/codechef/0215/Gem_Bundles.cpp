#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, b, g;
        cin >> r >> b >> g;
        int sum = r + b + g;
        int minn = min(r, b);
        int minnn = min(minn, g);
        int result = minnn * 10;
        int resultt = result + (3 * (sum - minnn * 3));
        cout << resultt << endl;
    }

    // your code goes here

}