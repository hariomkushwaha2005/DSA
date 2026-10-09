#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        long long ans = LLONG_MIN;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sorted[i] = {nums[i], i};
            sum += nums[i] > 0 ? nums[i] : 0;
            ans = nums[i] > ans ? nums[i] : ans;
        }
        if (n == 1 || ans <= 0)
            return ans;
        if (k >= n / 3)
        {
            return sum;
        }
        sort(sorted.begin(), sorted.end(), greater<>());
        vector<int> rank(n);
        for (int i = 0; i < n; ++i)
        {
            rank[sorted[i].second] = i;
        }
        vector<int> in(n, -1);
        for (int i = 0; i < n; ++i)
        {
            priority_queue<int> pq;
            for (int j = 0; j < k; ++j)
            {
                pq.push(sorted[j].first);
                in[j] = i;
            }
            sum = 0;
            int idx = k;
            for (int j = i; j < n; ++j)
            {
                if (in[rank[j]] != i)
                {
                    pq.push(sorted[rank[j]].first);
                    in[rank[j]] = i;
                }
                else
                {
                    while (idx < n && in[idx] == i)
                        ++idx;
                    if (idx < n)
                    {
                        pq.push(sorted[idx].first);
                        in[idx] = i;
                        ++idx;
                    }
                }
                sum += pq.top();
                pq.pop();
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};