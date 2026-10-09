#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void chika(int sum, int i, int k, vector<int>& a, vector<vector<int>>& ans,
               vector<int>& v) {
        if (sum >= k || i == a.size()) {
            if (sum == k)
                ans.push_back(v);
            return;
        }
        v.push_back(a[i]);
        chika(sum + a[i], i, k, a, ans, v);
        v.pop_back();
        chika(sum, i + 1, k, a, ans, v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        chika(0, 0, target, candidates, ans, v);
        return ans;
    }
};