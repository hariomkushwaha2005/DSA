#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions,
                   vector<int>& diff) {
        vector<int> v(n, INT_MAX);
        v[0] = 0;
        int last = 0;
        for (auto& it : restrictions) {
            last = max(last, it[0]);
            v[it[0]] = it[1];
        }
        for (int i = 1; i < n; i++) {
            v[i] = min(v[i], v[i - 1] + diff[i - 1]);
        }
        for (int i = last - 1; i >= 0; i--) {
            v[i] = min(v[i], v[i + 1] + diff[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, v[i]);
        }
        return ans;
    }
};