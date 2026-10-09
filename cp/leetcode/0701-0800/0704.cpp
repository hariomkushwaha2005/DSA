#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bs(vector<int> nums, int target, int low, int high) {
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;
        int cur = nums[mid];
        if (cur == target)
            return mid;
        else if (cur < target)
            return bs(nums, target, mid + 1, high);
        return bs(nums, target, low, mid - 1);
    }
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size() - 1);
    }
};