#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }
};