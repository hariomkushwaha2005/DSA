#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSum(const vector<int> &nums, int k, int mul)
    {
        int freq[100001] = {0};
        int maxx = 0;
        for (int num : nums)
        {
            maxx = max(maxx, num);
            ++freq[num];
        }
        long long i = maxx;
        long long ans = 0;
        while (k)
        {
            while (!freq[i])
                --i;

            int take = min(k, freq[i]);
            k -= take;
            freq[i] -= take;

            int cntmul = min(take, mul);
            if (cntmul)
            {
                ans += ((i * cntmul * ((mul << 1) - cntmul + 1)) >> 1);
                mul -= cntmul;
                take -= cntmul;
            }
            if (take)
            {
                ans += take * i;
            }
        }
        return ans;
    }
};