#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x < n - 1 && ans[x + 1][y] == -1)
            {
                ans[x + 1][y] = ans[x][y] + 1;
                q.push({x + 1, y});
            }
            if (x > 0 && ans[x - 1][y] == -1)
            {
                ans[x - 1][y] = ans[x][y] + 1;
                q.push({x - 1, y});
            }
            if (y > 0 && ans[x][y - 1] == -1)
            {
                ans[x][y - 1] = ans[x][y] + 1;
                q.push({x, y - 1});
            }
            if (y < m - 1 && ans[x][y + 1] == -1)
            {
                ans[x][y + 1] = ans[x][y] + 1;
                q.push({x, y + 1});
            }
        }
        return ans;
    }
};