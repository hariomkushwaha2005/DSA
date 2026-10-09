#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        int first = 0, second = 1, third = 1;
        for (int i = 3; i <= n; ++i) {
            int cur = first + second + third;
            first = second;
            second = third;
            third = cur;
        }
        return third;
    }
};