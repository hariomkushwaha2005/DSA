#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int arr[101] = {0};
        for (int i = 0; i < n; i++) {
            arr[nums[i]]++;
        }
        int ans = 0;
        for (auto& x : arr) {
             ans += (x * (x - 1) / 2);
        }
        return ans;
    }
};