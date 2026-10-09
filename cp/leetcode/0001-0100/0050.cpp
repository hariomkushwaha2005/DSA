#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fujiwara(double x, long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n % 2 == 0) {
            x = x * x;
            n = n / 2;
            return fujiwara(x, n);
        } else
            return x * fujiwara(x, n - 1);
    }
    double myPow(double x, int n) {
        long num = n;
        if (n < 0) {
            return (1 / fujiwara(x, -1 * num));
        }
        return fujiwara(x, n);
    }
};