#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int i, int r, int c, int n, vector<vector<int>> &grid)
    {
        if (i == n * n)
            return true;

        if (r > 0 && c < n - 2 && grid[r - 1][c + 2] == i)
            return check(i + 1, r - 1, c + 2, n, grid);

        else if (r > 0 && c > 1 && grid[r - 1][c - 2] == i)
            return check(i + 1, r - 1, c - 2, n, grid);

        else if (r < n - 1 && c > 1 && grid[r + 1][c - 2] == i)
            return check(i + 1, r + 1, c - 2, n, grid);

        else if (r < n - 1 && c < n - 2 && grid[r + 1][c + 2] == i)
            return check(i + 1, r + 1, c + 2, n, grid);

        else if (r < n - 2 && c < n - 1 && grid[r + 2][c + 1] == i)
            return check(i + 1, r + 2, c + 1, n, grid);

        else if (r < n - 2 && c > 0 && grid[r + 2][c - 1] == i)
            return check(i + 1, r + 2, c - 1, n, grid);

        else if (r > 1 && c < n - 1 && grid[r - 2][c + 1] == i)
            return check(i + 1, r - 2, c + 1, n, grid);

        else if (r > 1 && c > 0 && grid[r - 2][c - 1] == i)
            return check(i + 1, r - 2, c - 1, n, grid);

        return false;
    }
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
            return 0;
        int n = grid.size();
        return check(1, 0, 0, n, grid);
    }
};