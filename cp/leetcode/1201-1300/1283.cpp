#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int division(vector<int>& nums, int threshold, int x) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (nums[i] + x - 1) / x;
            if (cnt > threshold)
                break;
        }
        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (division(nums, threshold, mid) <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};