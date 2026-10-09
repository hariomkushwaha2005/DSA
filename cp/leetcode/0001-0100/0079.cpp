#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kaguya(int i, int j, int ind, string& s, vector<vector<char>>& a) {
        if (ind == s.size())
            return true;
        if (i > 0 && a[i - 1][j] == s[ind]) {
            char c = a[i - 1][j];
            a[i - 1][j] = '0';
            if (kaguya(i - 1, j, ind + 1, s, a))
                return true;
            a[i - 1][j] = c;
        }
        if (i < a.size() - 1 && a[i + 1][j] == s[ind]) {
            char c = a[i + 1][j];
            a[i + 1][j] = '0';
            if (kaguya(i + 1, j, ind + 1, s, a))
                return true;
            a[i + 1][j] = c;
        }
        if (j > 0 && a[i][j - 1] == s[ind]) {
            char c = a[i][j - 1];
            a[i][j - 1] = '0';
            if (kaguya(i, j - 1, ind + 1, s, a))
                return true;
            a[i][j - 1] = c;
        }
        if (j < a[0].size() - 1 && a[i][j + 1] == s[ind]) {
            char c = a[i][j + 1];
            a[i][j + 1] = '0';
            if (kaguya(i, j + 1, ind + 1, s, a))
                return true;
            a[i][j + 1] = c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char c = board[i][j];
                    board[i][j] = '0';
                    if (kaguya(i, j, 1, word, board))
                        return true;
                    board[i][j] = c;
                }
            }
        }
        return false;
    }
};