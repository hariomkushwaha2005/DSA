#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(const vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> v(n + 1);
        for (int i = 0; i <= n; i++) {
            v[i].reserve(i);
        }
        vector<vector<int>> ans;
        ans.reserve(n);
        for (int i = 0; i < n; i++) {
            int size = groupSizes[i];
            v[size].push_back(i);
            if (v[size].size() == size) {
                ans.push_back(std::move(v[size]));
            }
        }
        return ans;
    }
};