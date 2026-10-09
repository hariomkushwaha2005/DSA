#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int meena(int m, int n, vector<vector<int>>& dp) {
        if (n == 1 || m == 1)
            return 1;
        if (dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = (meena(m - 1, n, dp) + meena(m, n - 1, dp));
    }
    int uniquePaths(int m, int n) {
        vector<int> row(n+1,0);
        for(int i=1;i<=m;i++){
            vector<int> temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(i==1&&j==1){
                    temp[j]=1;
                    continue;
                }
                int up=0,left=0;
                if(i>1) up=row[j];
                if(j>1) left=temp[j-1];
                temp[j]=up+left;
            }
            row=temp;
        }
        return row[n];
    }
};