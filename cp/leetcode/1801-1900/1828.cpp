#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries)
    {
        int n = queries.size();
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });
        vector<int> ans;
        ans.reserve(n);
        for (vector<int> &c : queries)
        {
            int cnt = 0;
            auto left = lower_bound(
                points.begin(), points.end(), c[0] - c[2],
                [](const vector<int> &a, int val)
                { return a[0] < val; });
            auto right = upper_bound(
                points.begin(), points.end(), c[0] + c[2],
                [](int val, const vector<int> &a)
                { return val < a[0]; });
            c[2] *= c[2];
            for (auto it = left; it != right; ++it)
            {
                int x = c[0] - (*it)[0];
                int y = c[1] - (*it)[1];
                if (c[2] >= x * x + y * y)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};