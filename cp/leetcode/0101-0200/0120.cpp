#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int roza(vector<vector<int>>& nums, int i, int j, vector<vector<int>>& dp) {
        int n = nums.size();
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == n - 1)
            return dp[i][j] = nums[i][j];
        int a = roza(nums, i + 1, j, dp);
        int b = roza(nums, i + 1, j + 1, dp);
        return dp[i][j] = nums[i][j] + min(a, b);
    }
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prev(n,0);
        for(int i=n-1;i>=0;i--){
            vector<int> cur(n,0);
            for(int j=i;j>=0;j--){
                int a=0,b=0;
                if(i<n-1) a=prev[j];
                if(i<n-1) b=prev[j+1];
                cur[j]=nums[i][j]+min(a,b);
            }
            prev=cur;
        }
        return prev[0];
    }
};