#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool xo(int num, int row, int col, vector<vector<char>>& bo) {
        for (int i = 0; i < 9; i++) {
            if ((bo[row][i] - '0') == num || (bo[i][col] - '0' == num))
                return false;
        }
        row = 3 * (row / 3);
        col = 3 * (col / 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (bo[row + i][col + j] - '0' == num)
                    return false;
            }
        }
        return true;
    }
    void kaguya(int row, int col, vector<vector<char>>& bo,
                vector<vector<char>>& ans) {
        if (col == 9) {
            row++;
            col = 0;
        }
        if (row == 9) {
            ans = bo;
            return;
        }
        if (bo[row][col] != '.') {
            kaguya(row, col + 1, bo, ans);
            return;
        }
        for (int i = 1; i <= 9; i++) {
            if (xo(i, row, col, bo)) {
                bo[row][col] = '0' + i;
                kaguya(row, col + 1, bo, ans);
                bo[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ans = board;
        kaguya(0, 0, board, ans);
        board = ans;
    }
};