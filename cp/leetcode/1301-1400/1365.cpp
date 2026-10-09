#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int arr[102] = {0};
        vector<int> ans(n);
        for (int num : nums) {
            arr[num + 1]++;
        }
        for (int i = 1; i < 101; i++) {
            arr[i] += arr[i - 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = arr[nums[i]];
        }
        return ans;
    }
};