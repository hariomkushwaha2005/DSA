#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void kaguya(int ind, vector<int>& v, vector<int>& a,
                vector<vector<int>>& ans) {
        ans.push_back(v);
        for (int i = ind; i < a.size(); i++) {
            if (i > ind && a[i] == a[i - 1])
                continue;
            v.push_back(a[i]);
            kaguya(i + 1, v, a, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        kaguya(0, v, nums, ans);
        return ans;
    }
};