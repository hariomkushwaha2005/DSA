#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int arr[10001] = {0};
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        vector<int> ans = {0, 0};
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0)
                ans[1] = i;
            if (arr[i] == 2)
                ans[0] = i;
        }
        return ans;
    }
};