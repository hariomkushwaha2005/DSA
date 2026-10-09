#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;
        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {-1, 0, 1, 0};
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    vis[i][j] = 1;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int x = r + row[k];
                            int y = c + col[k];

                            if (x >= 0 && x < n && y >= 0 && y < m &&
                                grid[x][y] == '1' && !vis[x][y])
                            {
                                vis[x][y] = 1;
                                q.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};