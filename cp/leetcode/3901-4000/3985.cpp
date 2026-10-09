#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct rollh
    {
        long long base = 911382323;
        long long mod = 1e9 + 7;
        vector<long long> rh;
        vector<long long> power;
        rollh(const vector<int> &nums)
        {
            int n = nums.size();
            power.resize(n + 1, 1);
            rh.resize(n + 1, 0);
            for (int i = 0; i < n; ++i)
            {
                power[i + 1] = power[i] * base % mod;
                rh[i + 1] = (rh[i] * base % mod + nums[i]) % mod;
            }
        }
        long long gethash(int l, int r)
        {
            return (rh[r + 1] - (rh[l] * power[r + 1 - l]) % mod + mod) % mod;
        }
    };

public:
    long long getSum(vector<int> &nums)
    {
        int n = nums.size();
        rollh rh = rollh(nums);

        vector<int> revnum(nums.rbegin(), nums.rend());
        rollh rrh = rollh(revnum);

        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            pre[i + 1] = pre[i] + nums[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = 0, h = min(i, n - 1 - i);
            while (l <= h)
            {
                int mid = l + (h - l) / 2;
                int s = i - mid, e = i + mid;
                if (rh.gethash(s, e) == rrh.gethash(n - 1 - e, n - 1 - s))
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
            ans = max(ans, pre[i + l] - pre[i - l + 1]);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                int l = 0, h = min(i, n - 2 - i);
                while (l <= h)
                {
                    int mid = l + (h - l) / 2;
                    int s = i - mid, e = i + mid + 1;
                    if (rh.gethash(s, e) == rrh.gethash(n - 1 - e, n - 1 - s))
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        h = mid - 1;
                    }
                }
                ans = max(ans, pre[i + l + 1] - pre[i - l + 1]);
            }
        }
        return ans;
    }
};