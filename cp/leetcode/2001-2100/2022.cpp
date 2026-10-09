#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        int size = nums.size();
        if (size != m * n)
            return {};
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < size; ++i) {
            ans[i / n][i % n] = nums[i];
        }
        return ans;
    }
};