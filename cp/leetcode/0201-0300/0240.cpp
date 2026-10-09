#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int row = n - 1, col = 0;
        while (row >= 0 && col < m) {
            if (mat[row][col] == target)
                return true;
            else if (mat[row][col] > target)
                row--;
            else
                col++;
        }
        return false;
    }
};