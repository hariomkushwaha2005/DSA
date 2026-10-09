#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int pow(long long n, long long x) {
        n %= mod;
        if (x == 0)
            return 1;

        long long one = pow(n * n % mod, x / 2);
        return x & 1 ? n * one % mod : one;
    }

public:
    int mod = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long ans = pow(20, n / 2);
        return n & 1 ? 5 * ans % mod : ans;
    }
};