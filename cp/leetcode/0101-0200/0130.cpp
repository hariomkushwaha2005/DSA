#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(queue<pair<int, int>> &q, vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> st;
        bool flag = true;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            st.push({x, y});
            if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
            {
                flag = false;
            }
            if (x < n - 1 && board[x + 1][y] == 'O')
            {
                board[x + 1][y] = 'Z';
                q.push({x + 1, y});
            }
            if (x > 0 && board[x - 1][y] == 'O')
            {
                board[x - 1][y] = 'Z';
                q.push({x - 1, y});
            }
            if (y < m - 1 && board[x][y + 1] == 'O')
            {
                board[x][y + 1] = 'Z';
                q.push({x, y + 1});
            }
            if (y > 0 && board[x][y - 1] == 'O')
            {
                board[x][y - 1] = 'Z';
                q.push({x, y - 1});
            }
        }
        while (!st.empty())
        {
            int x = st.front().first;
            int y = st.front().second;
            st.pop();
            if (flag)
                board[x][y] = 'X';
            else
                board[x][y] = 'Y';
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'Z';
                    q.push({i, j});
                    bfs(q, board);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'Y')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};