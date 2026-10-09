#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    cnt++;
            }
        }
        if (cnt == 0)
            return 0;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for (auto it : dir)
                {
                    int x = it.first;
                    int y = it.second;
                    if (a + x < 0 || a + x >= m || b + y < 0 || b + y >= n)
                        continue;
                    if (grid[a + x][b + y] == 1)
                    {
                        cnt--;
                        grid[a + x][b + y] = 2;
                        q.push({a + x, b + y});
                    }
                }
            }
            ans++;
        }
        return cnt == 0 ? ans - 1 : -1;
    }
};