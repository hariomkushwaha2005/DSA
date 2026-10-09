#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void mikasa(int st, int end, int freeSt, int freeEnd,
                vector<vector<int>> &ans)
    {
        if (end < freeSt || st > freeEnd)
        {
            ans.push_back({st, end});
        }
        else if (st < freeSt && end > freeEnd)
        {
            ans.push_back({st, freeSt - 1});
            ans.push_back({freeEnd + 1, end});
        }
        else if (st < freeSt)
        {
            ans.push_back({st, freeSt - 1});
        }
        else if (end > freeEnd)
        {
            ans.push_back({freeEnd + 1, end});
        }
    }

public:
    vector<vector<int>>
    filterOccupiedIntervals(vector<vector<int>> &occupiedIntervals,
                            int freeStart, int freeEnd)
    {
        int n = occupiedIntervals.size();
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> ans;
        ans.reserve(n);

        int st = occupiedIntervals[0][0], end = occupiedIntervals[0][1];
        for (int i = 1; i < n; ++i)
        {
            int curst = occupiedIntervals[i][0],
                curend = occupiedIntervals[i][1];
            if (curst <= end + 1)
            {
                end = end > curend ? end : curend;
            }
            else
            {
                mikasa(st, end, freeStart, freeEnd, ans);
                st = curst;
                end = curend;
            }
        }
        mikasa(st, end, freeStart, freeEnd, ans);
        return ans;
    }
};