#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxx = 0;
        for (auto& it : accounts) {
            maxx = max(maxx, accumulate(it.begin(), it.end(), 0));
        }
        return maxx;
    }
};