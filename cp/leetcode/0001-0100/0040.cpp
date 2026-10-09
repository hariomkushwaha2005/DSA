#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void kaguya(int i, int k, vector<int>& v, vector<int>& a,
                vector<vector<int>>& ans) {
        if (k == 0) ans.push_back(v);
        for (int j = i; j < a.size(); j++) {
            if (j > i && a[j] == a[j - 1])
                continue;
            if(a[j]>k) break;
            v.push_back(a[j]);
            kaguya(j + 1, k - a[j], v, a, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        kaguya(0, target, v, candidates, ans);
        return ans;
    }
};