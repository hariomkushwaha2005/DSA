#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1e9;
        for (int i = 0; i < n; ++i)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int cur = nums[i] + nums[j] + nums[k];
                if (abs(target - cur) < abs(target - ans))
                    ans = cur;
                if (cur > target)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};