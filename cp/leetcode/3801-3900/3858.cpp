#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0, mask = 0;
        for (int i = 17; i >= 0; i--) {
            int num = mask | (1 << i);
            bool fine = true;
            for (int j = 0; j < m; j++) {
                bool match = false;
                for (int k = 0; k < n; k++) {
                    if ((num & grid[j][k]) == 0) {
                        match = true;
                        break;
                    }
                }
                if (!match) {
                    fine = false;
                    ans |= (1 << i);
                    break;
                }
            }
            if (fine) {
                mask = num;
            }
        }
        return ans;
    }
};