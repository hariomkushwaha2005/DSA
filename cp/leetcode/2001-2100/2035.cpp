#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> left(1 + (n >> 1));
        vector<vector<int>> right(1 + (n >> 1));

        for (int mask = 0; mask < (1 << (n >> 1)); mask++)
        {
            int size = 0, suml = 0, sumr = 0;
            for (int i = 0; i < (n >> 1); ++i)
            {
                if ((1 << i) & mask)
                {
                    suml += nums[i];
                    sumr += nums[n - 1 - i];
                    size++;
                }
            }
            left[size].push_back(suml);
            right[size].push_back(sumr);
        }
        for (int i = 0; i <= (n >> 1); ++i)
        {
            sort(left[i].begin(), left[i].end());
            sort(right[i].begin(), right[i].end());
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = (total >> 1);
        int ans = INT_MAX;
        for (int sz = 0; sz <= (n >> 1); ++sz)
        {
            for (int a : left[sz])
            {
                int rsz = (n >> 1) - sz;
                auto it = lower_bound(right[rsz].begin(), right[rsz].end(),
                                      target - a);
                if (it != right[rsz].end())
                {
                    ans = min(ans, abs(total - ((a + *it) << 1)));
                }
                if (it != right[rsz].begin())
                {
                    --it;
                    ans = min(ans, abs(total - ((a + *it) << 1)));
                }
            }
        }
        return ans;
    }
};