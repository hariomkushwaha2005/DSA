#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, freq = 1;
        long long sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum = sum + nums[r];
            long long ops = 1LL * nums[r] * (r - l + 1) - sum;
            while (ops > k) {
                sum = sum - nums[l];
                l++;
                ops = 1LL * nums[r] * (r - l + 1)- sum;
            }
            freq = max(freq, (r - l + 1));
        }
        return freq;
    }
};