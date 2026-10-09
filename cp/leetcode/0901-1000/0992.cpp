#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atleast(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, ans = 0, l = 0;
        while (i < nums.size()) {
            mp[nums[i]]++;
            while (mp.size() == k) {
                ans += (n - i);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            i++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atleast(nums, k) - atleast(nums, k + 1);
    }
};