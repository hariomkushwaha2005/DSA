#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int last = -1;
        vector<int> ans;
        for(int i = 0; i < n && ans.size() < k; i++){
            if(nums[i] != last) ans.push_back(nums[i]);
            last = nums[i];
        }
        return ans;
    }
};