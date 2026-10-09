#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void kaguya(int i, int k, int n, vector<int>& v, vector<vector<int>>& ans) {
        if (k < 0)
            return;
        if (k == 0 && n <= 0) {
            if (n == 0)
                ans.push_back(v);
            return;
        }
        for (int j = i; j <= 9; j++) {
            if (j > n)
                break;
            v.push_back(j);
            kaguya(j + 1, k - 1, n - j, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        kaguya(1, k, n, v, ans);
        return ans;
    }
};