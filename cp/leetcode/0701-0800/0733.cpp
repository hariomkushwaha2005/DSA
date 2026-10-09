#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int tar = image[sr][sc];
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        while (!q.empty())
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
                if (image[a + x][b + y] == tar && !vis[a + x][b + y])
                {
                    q.push({a + x, b + y});
                    image[a + x][b + y] = color;
                    vis[a + x][b + y] = 1;
                }
            }
        }
        return image;
    }
};