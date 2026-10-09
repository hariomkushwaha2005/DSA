#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void kaguya(int row, vector<int>& col, vector<int>& up, vector<int>& low,
                vector<string>& v, vector<vector<string>>& ans) {
        int n = col.size();
        if (row == n) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (col[i] == 0 && up[n - 1 + row - i] == 0 && low[row + i] == 0) {
                col[i] = 1;
                up[n - 1 + row - i] = 1;
                low[row + i] = 1;
                v[row][i] = 'Q';
                kaguya(row + 1, col, up, low, v, ans);
                col[i] = 0;
                up[n - 1 + row - i] = 0;
                low[row + i] = 0;
                v[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, 0);
        vector<int> up((2 * n) - 1, 0);
        vector<int> low((2 * n) - 1, 0);
        string s = "";
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        vector<string> v(n, s);
        vector<vector<string>> ans;
        kaguya(0, col, up, low, v, ans);
        return ans;
    }
};