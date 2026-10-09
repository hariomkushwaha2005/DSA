#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        long long s;
        int c;
    };
    long long INF = 1000000000000000000LL;
    int dq[100005];
    Node dp[100005];

    long long maximumSum(const vector<int> &nums, int m, int l, int r)
    {
        int n = nums.size();

        vector<long long> presum(n + 1);
        presum[0] = 0;

        for (int i = 0; i < n; ++i)
            presum[i + 1] = presum[i] + nums[i];

        long long single = miyuki(l, r, presum);
        if (single <= 0)
            return single;

        long long ans = -INF;
        long long low = 0, high = single;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            Node cur = kaguya(mid, l, r, presum);
            if (cur.c <= m)
            {
                ans = cur.s + mid * m;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

private:
    Node kaguya(long long mid, int l, int r, const vector<long long> &presum)
    {
        int n = presum.size() - 1;
        dp[n] = {0, 0};
        int head = 0, tail = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int j = i + l;
            if (j <= n)
            {
                while (head < tail)
                {
                    int x = dq[tail - 1];
                    long long val1 = dp[j].s + presum[j];
                    long long val2 = dp[x].s + presum[x];
                    if (val1 > val2 || (val1 == val2 && dp[j].c <= dp[x].c))
                        tail--;
                    else
                        break;
                }
                dq[tail++] = j;
            }
            while (head < tail && dq[head] > i + r)
                head++;
            dp[i] = dp[i + 1];
            if (head < tail)
            {
                long long val =
                    dp[dq[head]].s + presum[dq[head]] - presum[i] - mid;
                if (dp[i].s < val ||
                    (dp[i].s == val && dp[i].c > dp[dq[head]].c + 1))
                    dp[i] = {val, dp[dq[head]].c + 1};
            }
        }
        return dp[0];
    }
    long long miyuki(int l, int r, const vector<long long> &presum)
    {
        int n = presum.size() - 1;
        long long ans = -INF;
        int head = 0, tail = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int j = i + l;
            if (j <= n)
            {
                while (head < tail)
                {
                    if (presum[j] > presum[dq[tail - 1]])
                        tail--;
                    else
                        break;
                }
                dq[tail++] = j;
            }
            while (head < tail && dq[head] > i + r)
                head++;
            if (head < tail)
            {
                long long val = presum[dq[head]] - presum[i];
                ans = max(ans, val);
            }
        }
        return ans;
    }
};