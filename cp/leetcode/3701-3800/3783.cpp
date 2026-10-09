#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int ld = 0, rn = 0;
        int g = n;
        while (n > 0) {
            ld = n % 10;
            n = n / 10;
            rn = rn * 10 + ld;
        }
        return abs(rn - g);
    }
};