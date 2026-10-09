#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1)
                return INT_MAX;
            if (divisor == 1)
                return INT_MIN;
        }
        int ans = 0;
        int sign = 0;

        if (divisor < 0)
            sign = !sign;
        else
            divisor = -divisor;

        if (dividend < 0)
            sign = !sign;
        else
            dividend = -dividend;
        int half_min = INT_MIN / 2;
        while (dividend <= divisor) {
            int temp = divisor;
            int m = 1;
            while (temp >= half_min && temp << 1 >= dividend) {
                temp <<= 1;
                m <<= 1;
            }
            dividend -= temp;
            if (INT_MIN + m < ans)
                ans -= m;
            else {
                ans = INT_MIN;
                break;
            }
        }
        return sign ? ans : ans == INT_MIN ? INT_MAX : -ans;
    }
};