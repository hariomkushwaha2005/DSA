#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robber(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int a = nums[ind] + robber(ind - 2, nums, dp);
        int b = robber(ind - 1, nums, dp);
        return dp[ind] = max(a, b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n, -1);
        vector<int> dpp(n, -1);
        dpp[0]=0;
        dpp[1]=nums[1];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int a=nums[i]+dp[i-2];
            int b=dp[i-1];
            dp[i]=max(a,b);
            if(i<n){
                int c=nums[i]+dpp[i-2];
                int d=dpp[i-1];
                dpp[i]=max(c,d);
            }
        }
        return max(dp[n-2], dpp[n-1]);
    }
};