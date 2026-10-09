#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxx = 0;
        for (auto& candy : candies) {
            maxx = max(maxx, candy);
        }
        vector<bool> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = maxx <= candies[i] + extraCandies;
        }
        return ans;
    }
};