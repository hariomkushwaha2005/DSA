#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDegrees(vector<vector<int>> &matrix)
    {
        vector<int> ans(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j])
                    ans[i]++;
            }
        }
        return ans;
    }
};