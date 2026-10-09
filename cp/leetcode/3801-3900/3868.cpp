#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums1[i]]++;
            mp[nums2[i]]--;
        }
        int ans = 0;
        for (auto it : mp) {
            if (it.second % 2 != 0)
                return -1;
            ans += abs(it.second);
        }
        return ans / 4;
    }
};