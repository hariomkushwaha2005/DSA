#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> dis(n, vector<int>(n, -1));
        dis[0][0] = 1;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int newx = x + i;
                    int newy = y + j;
                    if (newx >= 0 && newx < n && newy >= 0 && newy < n &&
                        grid[newx][newy] == 0 &&
                        (dis[newx][newy] == -1 ||
                         dis[newx][newy] > 1 + dis[x][y]))
                    {
                        dis[newx][newy] = 1 + dis[x][y];
                        if (newx == n - 1 && newy == n - 1)
                            return dis[newx][newy];
                        q.push({newx, newy});
                    }
                }
            }
        }
        return dis[n - 1][n - 1];
    }
};