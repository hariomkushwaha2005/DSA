#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rn = 0, ld;
        while (x != 0) {
            ld = x % 10;
            if (rn > INT_MAX / 10 || (rn == INT_MAX / 10 && ld > 7))
                return 0; // overflow for positive
            if (rn < INT_MIN / 10 || (rn == INT_MIN / 10 && ld < -8))
                return 0;
            rn = rn * 10 + ld;
            x = x / 10;
        }
        return rn;
    }
};