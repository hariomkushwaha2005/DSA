#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxRatings(const vector<vector<int>> &units)
    {
        int minn1 = INT_MAX;
        int minn2 = INT_MAX;
        long long ans = 0;
        for (const auto &v : units)
        {
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            for (int num : v)
            {
                if (num < min1)
                {
                    min2 = min1;
                    min1 = num;
                }
                else if (num < min2)
                {
                    min2 = num;
                }
            }
            ans += min2 == INT_MAX ? min1 : min2;
            minn1 = min(minn1, min1);
            minn2 = min(minn2, min2);
        }
        return minn2 == INT_MAX ? ans : ans - minn2 + minn1;
    }
};