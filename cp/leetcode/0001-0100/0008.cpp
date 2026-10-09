#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(string s, int i, long long num, int sign) {
        if (i >= s.length() || !isdigit(s[i]))
            return sign * num;
        num = (num * 10 + (s[i] - '0'));
        if (sign * num >= INT_MAX)
            return INT_MAX;
        if (sign * num <= INT_MIN)
            return INT_MIN;
        return helper(s, i + 1, num, sign);
    }
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ')
            i++;
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        return helper(s, i, 0, sign);
    }
};