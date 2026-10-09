#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int xorr(int x) {
        if (x < 0)
            return 0;
        int t = x % 4;
        if (t == 3)
            return 0;
        else if (t == 2)
            return x + 1;
        else if (t == 1)
            return 1;
        return x;
    }

public:
    int xorOperation(int n, int start) {
        return (((xorr((start >> 1) - 1) ^ xorr((start >> 1) + n - 1)) << 1) |
                ((n & 1) & (start & 1)));
    }
};