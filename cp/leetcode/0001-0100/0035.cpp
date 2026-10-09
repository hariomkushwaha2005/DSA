#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        long long low = 0, high = nums.size() - 1, ans=nums.size();
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] >= target){
                ans=mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};