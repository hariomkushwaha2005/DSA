#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i += 2) {
            while (nums[i]--) {
                ans.push_back(nums[i + 1]);
            }
        }
        return ans;
    }
};

