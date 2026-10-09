#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0;
        while (i < n / 2) {
            for (int j = i; j < n - 1 - i; ++j) {
                int cur = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = cur;
            }
            ++i;
        }
    }
};

