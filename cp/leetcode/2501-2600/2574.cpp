#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int lsum = 0, rsum = 0;
        for (int i = 0; i < n; i++)
        {
            ans[i] += lsum;
            ans[n - 1 - i] -= rsum;
            lsum += nums[i];
            rsum += nums[n - 1 - i];
        }
        for (int i = 0; i < n; i++)
            ans[i] = abs(ans[i]);
        return ans;
    }
};