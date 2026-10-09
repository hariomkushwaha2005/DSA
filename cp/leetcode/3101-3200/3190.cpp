#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (auto& ele : nums) {
            ans += min(ele % 3, 3 - ele % 3);
        }
        return ans;
    }
};