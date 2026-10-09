#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int freq[1001] = {0};
        for (auto& it : nums)
            freq[it]++;
        while (original <= 1000 && freq[original] > 0) {
            original <<= 1;
        }
        return original;
    }
};