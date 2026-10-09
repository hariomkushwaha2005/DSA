#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maxi = 0, maxx = INT_MIN;
            for (int i = 0; i < m; i++) {
                if (mat[mid][i] > maxx) {
                    maxi = i;
                    maxx = mat[mid][i];
                }
            }
            int up = mid == 0 ? INT_MIN : mat[mid - 1][maxi];
            int down = mid == n - 1 ? INT_MIN : mat[mid + 1][maxi];

            if (mat[mid][maxi] > up && mat[mid][maxi] > down)
                return {mid, maxi};
            else if (mat[mid][maxi] < up)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};