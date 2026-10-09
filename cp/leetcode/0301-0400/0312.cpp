#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int x = INT_MIN;
                for (int k = i + 1; k < j; k++) {
                    x = max(x, dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
                }
                dp[i][j] = x == INT_MIN ? 0 : x;
            }
        }
        return dp[0][n - 1];
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return matrixMultiplication(nums);
    }
};
