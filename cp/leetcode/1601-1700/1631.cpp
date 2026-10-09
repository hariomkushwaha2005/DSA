#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> eff(n, vector<int>(m, -1));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 0});
        eff[0][0] = 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};
        while (!pq.empty())
        {
            int dist = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if (x == n - 1 && y == m - 1)
            {
                return dist;
            }
            if (eff[x][y] < dist)
                continue;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    int d = max(abs(heights[x][y] - heights[nx][ny]), dist);
                    if (eff[nx][ny] == -1 || eff[nx][ny] > d)
                    {
                        eff[nx][ny] = d;
                        pq.push({d, nx, ny});
                    }
                }
            }
        }
        return eff[n - 1][m - 1];
    }
};