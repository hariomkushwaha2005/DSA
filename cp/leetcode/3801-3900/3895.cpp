#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;
        for (auto num : nums) {
            while (num > 0) {
                cnt += num % 10 == digit;
                num /= 10;
            }
        }
        return cnt;
    }
};