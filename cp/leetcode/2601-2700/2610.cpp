#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        ans.reserve(n);
        int arr[201] = {0};
        for (int i = 0; i < n; i++) {
            arr[nums[i]]++;
            ans.size() >= arr[nums[i]]
                ? ans[arr[nums[i]] - 1].push_back(nums[i])
                : ans.push_back({nums[i]});
        }
        return ans;
    }
};