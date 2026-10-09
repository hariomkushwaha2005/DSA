#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int d = 256;
        int mod = 101;
        int vala = 0, valb = 0;
        int h = 1;
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % mod;
        }
        for (int i = 0; i < m; i++) {
            vala = (vala * d + a[i % n]) % mod;
            valb = (valb * d + b[i]) % mod;
        }
        for (int i = 0; i < n; i++) {
            if (vala == valb) {
                bool match = 1;
                for (int j = 0; j < m; j++) {
                    if (a[(i + j) % n] != b[j]) {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    return (i + m + n - 1) / n;
                }
            }
            vala = ((vala - h * a[i]) * d + a[(i + m) % n]) % mod;
            if (vala < 0)
                vala += mod;
        }
        return -1;
    }
};