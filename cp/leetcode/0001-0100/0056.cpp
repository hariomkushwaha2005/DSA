#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        if (n == 0)
            return {};
        vector<int> x = intervals[0];
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] <= x[1]) {
                x[0] = min(x[0], intervals[i][0]);
                x[1] = max(x[1], intervals[i][1]);
            } else {
                v.push_back(x);
                x = intervals[i];
            }
        }
        v.push_back(x);
        return v;
    }
};